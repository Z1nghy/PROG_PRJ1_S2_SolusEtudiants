//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet 2 - Calculs Trigo
// Nom du fichier 		: FctCalculTrigo.c
// Date de cr�ation 	: 14.02.2024
// Date de modification : 14.02.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : 
//
// Remarques			: voir donnee de l'�preuve            
//----------------------------------------------------------------------------------//

//-- definission pour utiliser la lib math sous VS --// 
#define _USE_MATH_DEFINES
#include "CalculTrigo.h"

//--- librairie standart ---//
#include "math.h"
//--- librairie perso ---//


/* ----------------------------------------------------------------------------------
// -> NOM FCT					: InitialiserStructure 
// -> PARAMETRES ENTRES			: 
// -> PARAMETRE SORTIE			: e_validation 
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle 
// -> description				: tous les champs de la structure seront mis � z�ro
 ----------------------------------------------------------------------------------*/
e_validation initialiserStructure(str_triangleRectangle* pt_strTriangle)
{
	//-- d�claration variables --// 
	//-- pirmaire --// 
	uint8_t i = 0;

	//-- enumeration --// 
	e_validation checkFct = nok;

	//-- boucle pour initilaiser le tableau des angles --//
	for (i = 0; i < 4; i++)
	{
		pt_strTriangle->tb_Angle[i] = 0;
	}
	//-- initialisation des cot�s -> adj - hyp - opp --// 
	pt_strTriangle->triangle_s.adjacent = 0;
	pt_strTriangle->triangle_s.hypotenuse = 0;
	pt_strTriangle->triangle_s.oppose = 0;

	//-- initialisation des champs de air et perim�tres --// 
	pt_strTriangle->air = 0;
	pt_strTriangle->perimetre = 0;

	//-- validation -> de la fct --// 
	checkFct = ok;

	//-- valeur � retourner --// 
	return checkFct;
}
	

/* ----------------------------------------------------------------------------------
// -> NOM FCT					: Conversion_DegRad
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			: 
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: depuis un angle en degr� -> d�terminer sa valeur 
//								  en radian 
 ----------------------------------------------------------------------------------*/
void Conversion_DegRad(str_triangleRectangle* pt_strTriangle)
{
	//-- test si angle � convertir --//
	///-- test si angle � convertir --//          
	if (pt_strTriangle->tb_Angle[0] != 0.0) {
		//--> alpha 
		pt_strTriangle->tb_Angle[1] = (float)(M_PI / 180) * pt_strTriangle->tb_Angle[0];
	}
	if (pt_strTriangle->tb_Angle[2] != 0.0) {
		//--> beta 
		pt_strTriangle->tb_Angle[3] = (float)(M_PI / 180) * pt_strTriangle->tb_Angle[2];
	}
}



/* ----------------------------------------------------------------------------------
// -> NOM FCT					: Conversion_RadDeg
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			:
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: depuis un angle en radian -> d�terminer sa valeur
//								  en degr�
 ----------------------------------------------------------------------------------*/
void Conversion_RadDeg(str_triangleRectangle* pt_strTriangle)
{
	//-- test si angle � convertir --//
	//--> alpha 
	if (pt_strTriangle->tb_Angle[1] != 0.0)
	{
		pt_strTriangle->tb_Angle[0] = (float)(180 / M_PI) * pt_strTriangle->tb_Angle[1];
	}
	//--> beta 
	if (pt_strTriangle->tb_Angle[3] != 0.0) 
	{
		//--> beta 
		pt_strTriangle->tb_Angle[2] = (float)(180 / M_PI) * pt_strTriangle->tb_Angle[3];
	}
}


/* ----------------------------------------------------------------------------------
// -> NOM FCT					: CalculAllAngles
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			: e_validation
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: si angle rentr� alors alors d�termine le 2�me angle 
 ----------------------------------------------------------------------------------*/
e_validation CalculerAllAngles(str_triangleRectangle* pt_strTriangle)
{
	e_validation checkFct = nok;

	if ((pt_strTriangle->tb_Angle[0] == 0) && (pt_strTriangle->tb_Angle[1] == 0) && (pt_strTriangle->tb_Angle[2] == 0) && (pt_strTriangle->tb_Angle[3] == 0))
	{
		//-- si cot� non d�fini -> hypoth�nuse
		if (pt_strTriangle->triangle_s.hypotenuse == 0)
		{
			//-- fonction trigo invers�e arctan
			pt_strTriangle->tb_Angle[1] = (float)atan((double)pt_strTriangle->triangle_s.oppose / (double)pt_strTriangle->triangle_s.adjacent);
			//-- conversion Radian - Degr� 
			Conversion_RadDeg(pt_strTriangle);
		}
		//-- si cot� non d�fini -> adjacent
		if (pt_strTriangle->triangle_s.adjacent == 0)
		{
			//-- fonction trigo invers�e arcsin 
			pt_strTriangle->tb_Angle[1] = (float)asin((double)pt_strTriangle->triangle_s.hypotenuse / (double)pt_strTriangle->triangle_s.oppose);
			//-- conversion Radian - Degr� 
			Conversion_RadDeg(pt_strTriangle);
		}
		//-- si cot� non d�fini -> oppos�
		if (pt_strTriangle->triangle_s.oppose == 0)
		{
			//-- fonction trigo invers�e arccos
			pt_strTriangle->tb_Angle[1] = (float)acos((double)pt_strTriangle->triangle_s.adjacent / (double)pt_strTriangle->triangle_s.hypotenuse);
			//-- conversion Radian - Degr� 
			Conversion_RadDeg(pt_strTriangle);
		}
	}

	//-- Verifie si alpha est inser�
	if (pt_strTriangle->tb_Angle[2] != 0)
	{
		//-- calcul de alpha
		pt_strTriangle->tb_Angle[0] = 90 - pt_strTriangle->tb_Angle[2];
		//-- conversion Degr� - Radian 
		Conversion_DegRad(pt_strTriangle);
	}
	//-- Verifie si Beta est inser�
	if (pt_strTriangle->tb_Angle[0] != 0)
	{
		//-- calcul de Beta 
		pt_strTriangle->tb_Angle[2] = 90 - pt_strTriangle->tb_Angle[0];

		//-- conversion Degr� - Radian 
		Conversion_DegRad(pt_strTriangle);
	}


	

	//-- test si tous les champs sont remplis 
	if ((pt_strTriangle->tb_Angle[0] != 0.0) && (pt_strTriangle->tb_Angle[1] != 0.0) && (pt_strTriangle->tb_Angle[2] != 0.0) && (pt_strTriangle->tb_Angle[3] != 0.0))
	{
		//-- retourne OK 
		checkFct = ok;
		
	}

	return checkFct;

}

/* ----------------------------------------------------------------------------------
// -> NOM FCT					: CalculerLongeursSgements
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			: e_validation
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: calculer les diff�rents segments du triangle 
//								  [adjacent - hypoth�nuse - oppos�] 
//								  selon les param�tres ins�rer par l'utilisateur
 ----------------------------------------------------------------------------------*/
e_validation CalculerLongeurSegment(str_triangleRectangle* pt_strTriangle)
{
	e_validation checkFct = nok;

	//-- test -> si aucun angle d�finit 
	if ((pt_strTriangle->tb_Angle[0] == 0) && (pt_strTriangle->tb_Angle[1] == 0) && (pt_strTriangle->tb_Angle[2] == 0) && (pt_strTriangle->tb_Angle[3] == 0))
	{
		CalculerAllAngles(pt_strTriangle);
		//-- test si la valeur � calculer est � z�ro 
		if ((pt_strTriangle->triangle_s.hypotenuse) == 0)
		{
			//-- calculer segment hypoth�nuse --// 
			pt_strTriangle->triangle_s.hypotenuse = sqrt(pow((double)pt_strTriangle->triangle_s.adjacent,2) + pow((double)pt_strTriangle->triangle_s.oppose, 2));
		}
		if ((pt_strTriangle->triangle_s.adjacent) == 0)
		{
			//-- calculer segment adjacent --//
			pt_strTriangle->triangle_s.adjacent = sqrt(pow((double)pt_strTriangle->triangle_s.hypotenuse, 2) - pow((double)pt_strTriangle->triangle_s.oppose, 2));
		}
		if ((pt_strTriangle->triangle_s.oppose) == 0)
		{
			//-- calculer segment oppos� 
			pt_strTriangle->triangle_s.oppose = sqrt(pow((double)pt_strTriangle->triangle_s.hypotenuse, 2) - pow((double)pt_strTriangle->triangle_s.adjacent, 2));
		}
	}
	

	//-- test si un angle a �t� d�finit alpha ou beta 
	if ((pt_strTriangle->tb_Angle[0] != 0) || (pt_strTriangle->tb_Angle[2] != 0))
	{
		//-- test si l'angle alpha a �t� ins�r� 
		if (pt_strTriangle->tb_Angle[0] != 0)
		{
			//-- conversion de alpha -> � -> radian 
			Conversion_DegRad(pt_strTriangle);

			//-- test si sgement hypoth�nuse entr� 
			if ((pt_strTriangle->triangle_s.hypotenuse) != 0)
			{
				//Calcul -> cos(alpha) = adj / hyp => ... 
				pt_strTriangle->triangle_s.adjacent = (float)cos((double)pt_strTriangle->tb_Angle[1]) * (double)pt_strTriangle->triangle_s.hypotenuse;
				//Calcul -> sin(alpha) = opp / hyp => ...
				pt_strTriangle->triangle_s.oppose = (float)sin((double)pt_strTriangle->tb_Angle[1]) * (double)pt_strTriangle->triangle_s.hypotenuse;
			}
			//-- test si sgement adjacent entr� 
			if ((pt_strTriangle->triangle_s.adjacent) != 0)
			{
				//Calcul -> cos(alpha) = adj/hyp => ...
				pt_strTriangle->triangle_s.hypotenuse = (double)pt_strTriangle->triangle_s.adjacent/ (float)cos((double)pt_strTriangle->tb_Angle[1]);
				//Calcul -> tan(alpha) = opp/adj => ...
				pt_strTriangle->triangle_s.oppose = (double)pt_strTriangle->triangle_s.adjacent * (float)tan((double)pt_strTriangle->tb_Angle[1]);
			}
			//-- test si sgement oppos� entr�  
			if ((pt_strTriangle->triangle_s.oppose) != 0)
			{
				//Calcul -> sin(alpha) = opp/hyp => ...
				pt_strTriangle->triangle_s.hypotenuse = (double)pt_strTriangle->triangle_s.oppose / (float)sin((double)pt_strTriangle->tb_Angle[1]);
				//Calcul -> tan(alpha) = opp/adj => ...
				pt_strTriangle->triangle_s.adjacent = (double)pt_strTriangle->triangle_s.oppose / (float)tan((double)pt_strTriangle->tb_Angle[1]);
			}
		}
	}

	//-- calcul de tous les angles -> appel de fct --// 
	CalculerAllAngles(pt_strTriangle);

	//-- check si la longeur des segments bien calcul� 
	if ((pt_strTriangle->triangle_s.hypotenuse != 0.0) && (pt_strTriangle->triangle_s.adjacent != 0.0) && (pt_strTriangle->triangle_s.oppose != 0.0))
	{
		checkFct = ok;
	}

	return checkFct;

}
	










