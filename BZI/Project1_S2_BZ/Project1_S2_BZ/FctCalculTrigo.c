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
#include <stdio.h>

//--- librairie perso ---//
#include"CalculTrigo.h"

/* ----------------------------------------------------------------------------------
// -> NOM FCT					: InitialiserStructure 
// -> PARAMETRES ENTRES			: 
// -> PARAMETRE SORTIE			: e_validation 
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle 
// -> description				: tous les champs de la structure seront mis à zéro
 ----------------------------------------------------------------------------------*/
e_validation checkFct(struct str_triangleRectangle, int* pt_strTriangle) {
	//-- déclaration variables --// 
	int i;
	//-- pirmaire --// 

	//-- enumeration --// 
	e_choixAngle;
	e_choixCote;
	e_choixCoteAngle;

	//-- boucle pour initilaiser le tableau des angles --//
	for (int i = 0; i < 5; i++) {
	
	}

	//-- initialisation des cotés -> adj - hyp - opp --// 
	struct str_coteTriangle1;

	//-- initialisation des champs de air et perimètres --// 
	int* pt_strTriangle = 0;
	//-- validation -> de la fct --// 
	e_validation;
}
	//-- valeur à retourner --// 

/* ----------------------------------------------------------------------------------
// -> NOM FCT					: Conversion_DegRad
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			: 
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: depuis un angle en degré -> déterminer sa valeur 
//								  en radian 
 ----------------------------------------------------------------------------------*/

	//-- test si angle à convertir --//
void Conversion_DegRad (struct str_triangleRectangle, int* pt_strTriangle) {

	struct str_triangleRectangle str_triangleRectangle1;

	//--> alpha 
	str_triangleRectangle1.tb_Angle[0] *= 3.14 / 180;
	str_triangleRectangle1.tb_Angle[1] *= 3.14 / 180;
	//--> beta 
	str_triangleRectangle1.tb_Angle[2] *= 3.14 / 180;
	str_triangleRectangle1.tb_Angle[3] *= 3.14 / 180;
	if (str_triangleRectangle1.tb_Angle == 0) {
		str_triangleRectangle1.tb_Angle[0,1,2,3] = 0;
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
void Conversion_RadDeg(struct str_triangleRectangle, int* pt_strTriangle) {

	struct str_triangleRectangle str_triangleRectangle1;
	//-- test si angle à convertir --//
	if (str_triangleRectangle1.tb_Angle > 1) {

	
	//--> alpha 
		str_triangleRectangle1.tb_Angle[0, 1] *= 180 / 3.14;

	//--> beta 
		str_triangleRectangle1.tb_Angle[2, 3] *= 180 / 3.14;
		if (str_triangleRectangle1.tb_Angle[0,1,2,3] == 0) {
			str_triangleRectangle1.tb_Angle[0, 1, 2, 3] = 0;
		}
	}
}
/* ----------------------------------------------------------------------------------
// -> NOM FCT					: CalculAllAngles
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			: e_validation
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: si angle rentré alors alors détermine le 2ème angle 
 ----------------------------------------------------------------------------------*/

	//-- test si un angle a été définit alpha ou beta 
e_validation checkFct(struct str_triangleRectangle, int* pt_strTriangle){
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
e_validation checkFct(struct str_triangleRectangle, int* pt_strTriangle) {
	struct str_triangleRectangle str_triangleRectangle1;
	//-- test -> si pas aucun angle définit 
	if(str_triangleRectangle1.tb_Angle[1,2,3,4]== 0){}
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










