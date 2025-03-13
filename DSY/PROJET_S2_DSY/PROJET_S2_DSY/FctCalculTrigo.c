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
#include "CalculTrigo.h"

//--- librairie standart ---//


//--- librairie perso ---//


/* ----------------------------------------------------------------------------------
// -> NOM FCT					: InitialiserStructure 
// -> PARAMETRES ENTRES			: 
// -> PARAMETRE SORTIE			: e_validation 
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle 
// -> description				: tous les champs de la structure seront mis à zéro
 ----------------------------------------------------------------------------------*/
int initialiserStructure(pt_strTriangle, str_triangleRectangle)
{
	//-- déclaration variables --// 

	//-- pirmaire --// 


	//-- enumeration --// 


	//-- boucle pour initilaiser le tableau des angles --//


	//-- initialisation des cotés -> adj - hyp - opp --// 


	//-- initialisation des champs de air et perimètres --// 


	//-- validation -> de la fct --// 


	//-- valeur à retourner --// 
}
	

/* ----------------------------------------------------------------------------------
// -> NOM FCT					: Conversion_DegRad
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			: 
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: depuis un angle en degré -> déterminer sa valeur 
//								  en radian 
 ----------------------------------------------------------------------------------*/
int Conversion_DegRad(pt_strTriangle, str_triangleRectangle)
{
	struct str_triangleRectangle* ptr_strTR;

	if (ptr_strTR->tb_Angle[0] != 0)
	{
		ptr_strTR->tb_Angle[1] =  ptr_strTR->tb_Angle[0] / 180;
	}
	if (ptr_strTR->tb_Angle[2] != 0)
	{
		ptr_strTR->tb_Angle[3] = ptr_strTR->tb_Angle[2] / 180;
	}
}



/* ----------------------------------------------------------------------------------
// -> NOM FCT					: Conversion_RadDeg
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			:
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: depuis un angle en radian -> déterminer sa valeur
//								  en degré
 ----------------------------------------------------------------------------------*/

	//-- test si angle à convertir --//
	// 
int Conversion_RadDeg(pt_strTriangle, str_triangleRectangle)
{
	struct str_triangleRectangle* ptr_strTR;

	if (ptr_strTR->tb_Angle[0] != 0)
	{
		ptr_strTR->tb_Angle[0] = 180 / ptr_strTR->tb_Angle[1];
	}
	else if (ptr_strTR->tb_Angle[2] != 0)
	{
		ptr_strTR->tb_Angle[2] = 180 / ptr_strTR->tb_Angle[3];
	}
	
}


/* ----------------------------------------------------------------------------------
// -> NOM FCT					: CalculAllAngles
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			: e_validation
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: si angle rentré alors alors détermine le 2ème angle 
 ----------------------------------------------------------------------------------*/
int CalculerAllAngles(pt_strTriangle, str_triangleRectangle)
{
	struct str_coteTriangle* ptr_str;
	struct str_triangleRectangle* ptr_strTR;
	//-- test si un angle a été définit alpha ou beta
	if ((ptr_strTR->tb_Angle[0] != 0) && (ptr_strTR->tb_Angle[0] == 0))
	{
		//-- calcul de Beta 
		ptr_strTR->tb_Angle[2] = 180 - ptr_strTR->tb_Angle[0] - 90;

			//-- conversion Degré - Radian 
		Conversion_DegRad(ptr_strTR->tb_Angle[0]);
	}
	else if ((ptr_strTR->tb_Angle[2] != 0) && (ptr_strTR->tb_Angle[0] == 0))
	{
		//-- calcul de alpha
		ptr_strTR->tb_Angle[0] = 180 - ptr_strTR->tb_Angle[2] - 90;
			//-- conversion Degré - Radian 
		Conversion_DegRad(ptr_strTR->tb_Angle[3]);
	}

	if ((ptr_strTR->tb_Angle[0] == 0) && (ptr_strTR->tb_Angle[2] == 0))
	{
		if (ptr_str->hypotenuse == 0)
		{
			ptr_strTR->tb_Angle[0] = 1/(ptr_str->adjacent / ptr_str->oppose);
			Conversion_RadDeg(ptr_strTR->tb_Angle[0]);
		}

		if (ptr_str->adjacent == 0)
		{
			ptr_strTR->tb_Angle[0] = 1 / (ptr_str->oppose / ptr_str->hypotenuse);
			Conversion_RadDeg(ptr_strTR->tb_Angle[0]);
		}

		if (ptr_str->oppose == 0)
		{
			ptr_strTR->tb_Angle[0] = 1 / (ptr_str->hypotenuse / ptr_str->adjacent);
			Conversion_RadDeg(ptr_strTR->tb_Angle[0]);
		}


	}


		

	//-- si pas d'angle défini 

		//-- si coté non défini -> hypothénuse -> fonction trigo inversée arctan 

			//-- conversion Radian - Degré 

		//-- si coté non défini -> opposé -> fonction trigo inversée arccos

			//-- conversion Radian - Degré 

		//-- si coté non défini -> adjacent -> fonction trigo inversée arcsin

			//-- conversion Radian - Degré 

	//-- test si tous les champs sont remplis 
	if ()
	{
		//-- retourne OK 
		return ok;
	}

		

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
int CalculerLongeurSegment(pt_strTriangle, str_triangleRectangle)
{
	struct str_coteTriangle* ptr_str;
	struct str_triangleRectangle* ptr_strTR;
	//-- test -> si pas aucun angle définit 

		//-- test si la valeur à calculer est à zéro 
	if ((ptr_str->hypotenuse) == 0)
	{
		ptr_str->hypotenuse = root(powf(ptr_str->adjacent) + powf(ptr_str->oppose));
	}
	if ((ptr_str->adjacent) == 0)
	{
		ptr_str->adjacent = root(powf(ptr_str->hypotenuse) - powf(ptr_str->oppose));
	}
	if ((ptr_str->oppose) == 0)
	{
		ptr_str->oppose = root(powf(ptr_str->hypotenuse) - powf(ptr_str->adjacent));
	}

	//-- test si un angle a été définit alpha ou beta 
	if ((ptr_strTR->tb_Angle == 1) || 2)
	{

		if ((ptr_str->hypotenuse) != 0)
		{
			ptr_strTR->tb_Angle[0] = ptr_str->adjacent / ptr_str->hypotenuse;
			ptr_strTR->tb_Angle[0] = ptr_str->oppose / ptr_str->hypotenuse;
		}

		if ((ptr_str->adjacent) != 0)
		{
			ptr_strTR->tb_Angle[0] = ptr_str->adjacent / ptr_str->hypotenuse;
			ptr_strTR->tb_Angle[0] = ptr_str->oppose / ptr_str->adjacent;
		}

		if ((ptr_str->oppose) != 0)
		{
			ptr_strTR->tb_Angle[0] = ptr_str->oppose / ptr_str->hypotenuse;
			ptr_strTR->tb_Angle[0] = ptr_str->oppose / ptr_str->adjacent;
		}
	}
		//-- test si l'angle alpha a été inséré 



	//-- calcul de tous les angles -> appel de fct --// 


	//-- check si la longeur des segments bien calculé 

}
	










