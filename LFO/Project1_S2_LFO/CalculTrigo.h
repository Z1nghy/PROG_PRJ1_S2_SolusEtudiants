//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet 2 - Calculs Trigo
// Nom du fichier 		: CalculsTrigo.h
// Date de création 	: 14.02.2024
// Date de modification : 14.02.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : 
//
// Remarques			: voir donnee de l'épreuve            
//----------------------------------------------------------------------------------//
#ifndef CALCUL_TRIGO_H
#define CALCUL_TRIGO_H

#include <stdint.h>

//-- déclaration -> définition globales --// 
#define NB_CHOIX_MAX 2
#define TAILLE_TB_ANGLE 4

//-- déclaration -> énumération globales --// 
typedef enum { cote, angle } e_choixCoteAngle;
typedef enum { adj = 1, hyp, opp } e_choixCote;
typedef enum { alpha = 1, beta } e_choixAngle;
typedef enum { ok, nok} e_validation;


//-- déclaration -> structure globales --// 
//--> structure 1
typedef struct {
	uint8_t adjacent;
	uint8_t hypotenuse;
	uint8_t oppose;

}str_coteTriangle;
//--> structure 2
typedef struct {
	float tb_Angle[TAILLE_TB_ANGLE];
	str_coteTriangle triangle_s;

	struct Str_AetP {
		uint16_t air;
		uint8_t perimetre;

	};

}str_triangleRectangle;


//-- déclaration de prototype --// 
	//-> tous les champs de la structure seront mis à zéro
	//-> conversion angle degré -> en radian 
	//-> conversion angle radian -> en degré 
	//-> calculer les différents segments du triangle
	//-> calculer les différents angles 

e_validation InitialiserStructure(str_triangleRectangle* pt_strTriangle);

void Conversion_DegRad(str_triangleRectangle* pt_strTriangle);

void Conversion_RadDeg(str_triangleRectangle* pt_strTriangle);

e_validation CalculerAllAngles(str_triangleRectangle* pt_strTriangle);

e_validation CalculerLongueurSegment(str_triangleRectangle* pt_strTriangle);

#endif // !CALCUL_TRIGO_H