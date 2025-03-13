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

/* ----------------------------------------------------------------------------------
// -> NOM FCT					: InitialiserStructure 
// -> PARAMETRES ENTRES			: 
// -> PARAMETRE SORTIE			: e_validation 
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle 
// -> description				: tous les champs de la structure seront mis à zéro
 ----------------------------------------------------------------------------------*/
e_validation InitialiserStructure(str_triangleRectangle *pt_strTriangle)
{
	//-- déclaration variables --// 
	//-- pirmaire --// 


	struct Str_AetP Str_AetP1;
	struct Str_AetP Str_AetP2;

	e_validation valRetour;
	//-- enumeration --// 


	//-- boucle pour initilaiser le tableau des angles --//
	for (char i = 0; i < 4; i++)
	{
		str_triangleRectangle tb_Angle[i] = 0; 
	}

	//-- initialisation des cotés -> adj - hyp - opp --// 
	
	//-- initialisation des champs de air et perimètres --// 
	Str_AetP1.air = 0;
	Str_AetP1.perimetre = 0;

	//-- validation -> de la fct --// 


	//-- valeur à retourner --// 
	return(valRetour);
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

		
	//--> beta 


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


	//--> beta 

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
	//-- test si un angle a été définit alpha ou beta 

		//-- calcul de alpha 

			//-- conversion Degré - Radian 

		//-- calcul de beta

			//-- conversion Degré - Radian 

	//-- si pas d'angle défini 

		//-- si coté non défini -> hypothénuse -> fonction trigo inversée arctan 

			//-- conversion Radian - Degré 

		//-- si coté non défini -> opposé -> fonction trigo inversée arccos

			//-- conversion Radian - Degré 

		//-- si coté non défini -> adjacent -> fonction trigo inversée arcsin

			//-- conversion Radian - Degré 

	//-- test si tous les champs sont remplis 

		//-- retourne OK 



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


}








