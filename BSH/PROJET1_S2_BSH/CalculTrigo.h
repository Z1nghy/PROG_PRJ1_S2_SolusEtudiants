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

//-- déclaration -> définition globales --// 
#define NB_CHOIX_MAX 2
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
	float tb_Angle[4];
	str_coteTriangle triangle_s;
	struct {
		uint8_t air;
		uint8_t perimetre
	}Str_AetP;
}str_triangleRectangle;

//-- déclaration de prototype --// 
	//-> tous les champs de la structure seront mis à zéro
	//-> conversion angle degré -> en radian 
	//-> conversion angle radian -> en degré 
	//-> calculer les différents segments du triangle
	//-> calculer les différents angles 
e_validation InitialiserStructure(int *pt_strTiangle, str_triangleRectangle);
void Conversion_DegRad(int* pt_strTiangle, str_triangleRectangle);
void Conversion_RadDeg(int* pt_strTiangle, str_triangleRectangle);
e_validation CalculerAllAngles(int *pt_strTiangle, str_triangleRectangle);
e_validation CalculerLongueurSegment(int* pt_strTiangle, str_triangleRectangle);
#endif // !CALCUL_TRIGO_H