//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet 2 - Calculs Trigo
// Nom du fichier 		: FctCalculTrigo.c
// Date de création 	: 14.02.2024
// Date de modification : 14.02.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : 
//
// Remarques			: voir donnee de l'épreuve            
//----------------------------------------------------------------------------------//

//-- definission pour utiliser la lib math sous VS --// 
#define _USE_MATH_DEFINES

//--- librairie standart ---//


//--- librairie perso ---//
#include "CalculTrigo.h"
#include <math.h>

/* ----------------------------------------------------------------------------------
// -> NOM FCT					: InitialiserStructure 
// -> PARAMETRES ENTRES			: 
// -> PARAMETRE SORTIE			: e_validation 
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle 
// -> description				: tous les champs de la structure seront mis à zéro
 ----------------------------------------------------------------------------------*/
e_validation InitialiserStructure(str_triangleRectangle* pt_strTriangle)
{
	//-- déclaration variables --// 
	//-- pirmaire --// 
	uint8_t i = 0;

	//-- enumeration --// 
	e_validation checkFct = nok;

	//-- boucle pour initilaiser le tableau des angles --//
	for (i = 0; i < TAILLE_TB_ANGLE; i++)
	{
		pt_strTriangle->tb_Angle[i] = 0;
	}
	//-- initialisation des cotés -> adj - hyp - opp --// 
	pt_strTriangle->triangle_s.adjacent = 0;
	pt_strTriangle->triangle_s.hypotenuse = 0;
	pt_strTriangle->triangle_s.oppose = 0;

	//-- initialisation des champs de air et perimètres --// 
	pt_strTriangle->air = 0;
	pt_strTriangle->perimetre = 0;

	//-- validation -> de la fct --// 
	checkFct = ok;

	//-- valeur à retourner --// 
	return checkFct;
}

/* ----------------------------------------------------------------------------------
// -> NOM FCT					: Conversion_DegRad
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			: 
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: depuis un angle en degré -> déterminer sa valeur 
//								  en radian 
 ----------------------------------------------------------------------------------*/
void Conversion_DegRad(str_triangleRectangle* pt_strTriangle)
{
	//-- test si angle à convertir --//
	//--> alpha 
	if (pt_strTriangle->tb_Angle[0] != (float)0.0) 
		pt_strTriangle->tb_Angle[1] = (pt_strTriangle->tb_Angle[0] * M_PI) / 180;

	//--> beta 
	if (pt_strTriangle->tb_Angle[2] != (float)0.0) 
		pt_strTriangle->tb_Angle[3] = (pt_strTriangle->tb_Angle[2] * M_PI) / 180;

}

/* ----------------------------------------------------------------------------------
// -> NOM FCT					: Conversion_RadDeg
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			:
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: depuis un angle en radian -> déterminer sa valeur
//								  en degré
 ----------------------------------------------------------------------------------*/
void Conversion_RadDeg(str_triangleRectangle* pt_strTriangle)
{
	//-- test si angle à convertir --//
	//--> alpha 
	if (pt_strTriangle->tb_Angle[1] != (float)0.0)
		pt_strTriangle->tb_Angle[0] = (pt_strTriangle->tb_Angle[1] * 180) / M_PI;

	//--> beta 
	if (pt_strTriangle->tb_Angle[3] != (float)0.0)
		pt_strTriangle->tb_Angle[2] = (pt_strTriangle->tb_Angle[3] * 180) / M_PI;

}

/* ----------------------------------------------------------------------------------
// -> NOM FCT					: CalculAllAngles
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			: e_validation
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: si angle rentré alors alors détermine le 2ème angle 
 ----------------------------------------------------------------------------------*/
e_validation CalculerAllAngles(str_triangleRectangle* pt_strTriangle)
{
	uint8_t i;
	e_validation checkFct = nok;

	//-- test si un angle a été définit alpha ou beta 
	if ((pt_strTriangle->tb_Angle[0]) || (pt_strTriangle->tb_Angle[2])) {
		//-- calcul de alpha 
		if (pt_strTriangle->tb_Angle[2])
			pt_strTriangle->tb_Angle[0] = 180 - (pt_strTriangle->tb_Angle[2] + 90);
			Conversion_DegRad(pt_strTriangle);	//-- conversion Degré - Radian 

		//-- calcul de beta
		if (pt_strTriangle->tb_Angle[0])
			pt_strTriangle->tb_Angle[2] = 180 - (pt_strTriangle->tb_Angle[0] + 90);
			Conversion_DegRad(pt_strTriangle);	//-- conversion Degré - Radian 
	}
	else {
		//-- si pas d'angle défini 

			//-- si coté non défini -> hypothénuse -> fonction trigo inversée arctan 
		if (pt_strTriangle->triangle_s.hypotenuse == 0) {
			pt_strTriangle->tb_Angle[0] = (float)atan(((double)(pt_strTriangle->triangle_s.adjacent) / (pt_strTriangle->triangle_s.oppose)));
			pt_strTriangle->tb_Angle[2] = 180 - (pt_strTriangle->tb_Angle[0] + 90);
			//-- conversion Radian - Degré 
			Conversion_DegRad(pt_strTriangle);
		}
			//-- si coté non défini -> opposé -> fonction trigo inversée arccos
		if (pt_strTriangle->triangle_s.oppose == 0) {
			pt_strTriangle->tb_Angle[0] = (float)acos(((double)(pt_strTriangle->triangle_s.oppose) / (pt_strTriangle->triangle_s.hypotenuse)));
			pt_strTriangle->tb_Angle[2] = 180 - (pt_strTriangle->tb_Angle[0] + 90);
			//-- conversion Radian - Degré 
			Conversion_DegRad(pt_strTriangle);
		}
			//-- si coté non défini -> adjacent -> fonction trigo inversée arcsin
		if (pt_strTriangle->triangle_s.adjacent == 0) {
			pt_strTriangle->tb_Angle[0] = (float)asin(((double)(pt_strTriangle->triangle_s.adjacent) / (pt_strTriangle->triangle_s.hypotenuse)));
			pt_strTriangle->tb_Angle[2] = 180 - (pt_strTriangle->tb_Angle[0] + 90);
			//-- conversion Radian - Degré 
			Conversion_DegRad(pt_strTriangle);
		}

	}
		
	//-- test si tous les champs sont remplis 
	for (i = 0; i < TAILLE_TB_ANGLE; i++)
	{
		if (pt_strTriangle->tb_Angle[i] == 0.0) {
			checkFct = nok;
			i = TAILLE_TB_ANGLE;	//forcer à sortire de la boucle pour retourner une erreur
		}
		else
			checkFct = ok;
			
	}
		//-- retourne OK 
	return checkFct;
}


/* ----------------------------------------------------------------------------------
// -> NOM FCT					: CalculerLongeursSgements
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			: e_validation
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: calculer les différents segments du triangle 
//								  [adjacent - hypothénuse - opposé] 
//								  selon les paramètres insérer par l'utilisateur
 ----------------------------------------------------------------------------------*/
e_validation CalculerLongueurSegment(str_triangleRectangle* pt_strTriangle)
{
	e_validation checkFct = nok;

	//-- test -> si pas aucun angle définit 

		//-- test si la valeur à calculer est à zéro 

			//-- calculer segment adjacent --//

			//-- calculer segment hypothénuse --// 

			//-- calculer segment opposé 

	//-- test si un angle a été définit alpha ou beta 

		//-- test si l'angle alpha a été inséré 

			//-- conversion de alpha -> ° -> radian 


			//-- test si sgement hypothénuse entré 

				//Calcul -> cos(alpha) = adj / hyp => ... 


				//Calcul -> sin(alpha) = opp / hyp => ...

			//-- test si sgement adjacent entré 

				//Calcul -> cos(alpha) = adj/hyp => ...


				//Calcul -> tan(alpha) = opp/adj => ...

			//-- test si sgement opposé entré  

				//Calcul -> sin(alpha) = opp/hyp => ...


				//Calcul -> tan(alpha) = opp/adj => ... 


	//-- calcul de tous les angles -> appel de fct --// 


	//-- check si la longeur des segments bien calculé 

	return checkFct;
}








