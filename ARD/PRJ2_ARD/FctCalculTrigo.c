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

#include "CalculTrigo.h"
#include "math.h"
#include "corecrt_math_defines.h"
//-- definission pour utiliser la lib math sous VS --// 
#define _USE_MATH_DEFINES

//--- librairie standart ---//


//--- librairie perso ---//


/* ----------------------------------------------------------------------------------
// -> NOM FCT					: InitialiserStructure 
// -> PARAMETRES ENTRES			: 
// -> PARAMETRE SORTIE			: e_validation 
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle 
// -> description				: tous les champs de la structure seront mis à zéro
 ----------------------------------------------------------------------------------*/
void Initialiserstructure() {
	//-- déclaration variables --// 
	//-- pirmaire --// 

	//-- enumeration --// 


	//-- boucle pour initilaiser le tableau des angles --//
	int tb_Angle[4] = { 1,2,3,4 };

	//-- initialisation des cotés -> adj - hyp - opp --// 
	char adjacent = 0;
	char hypotenuse = 0;
	char oppose = 0;
	//-- initialisation des champs de air et perimètres --// 
	int air = 0;
	int perimetre = 0;
	//-- validation -> de la fct --// 
	e_validation testFct = ok;

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
void Conversion_DegRad(){
	//-- test si angle à convertir --//
	//--> alpha 
	if (alpha > 0){
	alpha = alpha*(M_PI/180);
	}
	//--> beta 
	if (beta > 0) {
		beta = beta * (M_PI / 180);
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
void Conversion_RadDeg(){
	//-- test si angle à convertir --//
	//--> alpha 
	if (alpha > 0) {
		alpha = alpha * (180 / M_PI);
	}
	//--> beta 
	if (beta > 0) {
		beta = beta * (180 / M_PI);
	}
}
/* ----------------------------------------------------------------------------------
// -> NOM FCT					: CalculAllAngles
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			: e_validation
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: si angle rentré alors alors détermine le 2ème angle 
 ----------------------------------------------------------------------------------*/
void CalculerAllAngles(){
	//-- test si un angle a été définit alpha ou beta 

		//-- calcul de alpha 
	if (e_choixAngle == alpha) {
		//-- conversion Degré - Radian 
		alpha = Conversion_DegRad();
	}
		//-- calcul de beta
	else {
		//-- conversion Degré - Radian
		beta = Conversion_DegRad();
	} 
	//-- si pas d'angle défini 

		//-- si coté non défini -> hypothénuse -> fonction trigo inversée arctan 
		
			//-- conversion Radian - Degré 
	Conversion_RadDeg();
	
		//-- si coté non défini -> opposé -> fonction trigo inversée arccos
			
			//-- conversion Radian - Degré 
	Conversion_RadDeg();
	
		//-- si coté non défini -> adjacent -> fonction trigo inversée arcsin
		
			//-- conversion Radian - Degré 
	Conversion_RadDeg();
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
void CalculerLongueurSegment() {
	//-- test -> si pas aucun angle définit 

		//-- test si la valeur à calculer est à zéro 

			//-- calculer segment adjacent --//
	adjacent = ((hypotenuse * hypotenuse) - (oppose * oppose));
			//-- calculer segment hypothénuse --// 
	hypotenuse = ((oppose * oppose) + (oppose * oppose));
			//-- calculer segment opposé 
	oppose = ((hypotenuse * hypotenuse) - (adjacent * adjacent));
	//-- test si un angle a été définit alpha ou beta 
	alpha = Conversion_DegRad();
		//-- test si l'angle alpha a été inséré 
	if (alpha > 0){
				//-- conversion de alpha -> ° -> radian 
		alpha = Conversion_DegRad();

				//-- test si sgement hypothénuse entré 
		if (hypotenuse > 0){
					//Calcul -> cos(alpha) = adj / hyp => ... 
		cos alpha = adjacent / hypotenuse;

					//Calcul -> sin(alpha) = opp / hyp => ...
		sin alpha = oppose / hypotenuse;
		}
				//-- test si sgement adjacent entré 
		if (adjacent > 0) {
					//Calcul -> cos(alpha) = adj/hyp => ...
		cos alpha = adjacent / hypotenuse;

					//Calcul -> tan(alpha) = opp/adj => ...
		tan alpha = oppose / adjacent;
		}
				//-- test si sgement opposé entré  
		if (oppose > 0) {
					//Calcul -> sin(alpha) = opp/hyp => ...
		sin alpha = oppose / hypotenuse;

					//Calcul -> tan(alpha) = opp/adj => ... 
		tan alpha = oppose / adjacent;
		}
		//-- calcul de tous les angles -> appel de fct --// 
		CalculerAllAngles();

		//-- check si la longeur des segments bien calculé 
		
	}
}








