//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet 2 - Calculs Trigo
// Nom du fichier 		: CalculsTrigo.h
// Date de création 	: 28.02.2024
// Date de modification : 28.02.2024
//
// Auteur 				: Henri Mott
//
// Description          : un test
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
struct str_cotetringle
{
	char adjacent;
	char hypotenuse;
	char oppose;

};

//--> structure 2
struct Str_AetP
{
	int air;
	int perimetre;

};

//--> structure 3
struct str_triangleRectangle
{
	float tb_Angle[4]; // Tableux a 4 case

	int str_cotetringle; // a structure

	int Str_AetP;	// another structure

	short *pt_str; // Pointeur
};


//-- déclaration de prototype --// 
	//-> tous les champs de la structure seront mis à zéro
	//-> conversion angle degré -> en radian 
	//-> conversion angle radian -> en degré 
	//-> calculer les différents segments du triangle
	//-> calculer les différents angles 

int InitialiserStructure(char pt_strTriangle, int str_triangleRectangle, int e_validation)
{
	// Reset le flag de validation
	e_validation = 0;

	struct str_cotetringle cotetringle;

	struct Str_AetP AetP;

	struct str_triangleRectangle triangleRectangle;

	// Flag de validation
	e_validation = 1;
	
	//cotetringle = 0;
	return e_validation;
}



int Conversion_RadDeg(int pt_strTriangle, struct str_triangleRectangle* pt_str)
{
	// Declaration des variable de fonction
	int i = 0;
	float alpha_R = 0;
	float alpha_D = 0;
	float betta_R = 0;
	float betta_D = 0;

	// Pour chargé les valeur que le user a choisis dans la variable
	for (i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 1:
			alpha_R = pt_str->tb_Angle[0];	// Le pointeur met la neuvelle valeur dans notre variable, depuis le tableux que on n'a pointé

			// Test ci angle plus grand que 0, avant la conversions
			if (alpha_R > 0)
			{
				alpha_D = alpha_R * (180 / 3.14); // Conver rad en degré
			}
			break;

		case 2:
			alpha_D = pt_str->tb_Angle[1];

			//// Test ci angle plus grand que 0, avant la conversions
			//if (alpha_D > 0)
			//{
			//	alpha_R = alpha_D * (3.14 / 180); // Conver degré a rad
			//}
			break;

		case 3:
			betta_R = pt_str->tb_Angle[2];

			// Test ci angle plus grand que 0, avant la conversions
			if (betta_R > 0)
			{
				betta_D = betta_R * (180 / 3.14); // Conver rad en degré
			}
			break;

		case 4:
			betta_D = pt_str->tb_Angle[3];

			//// Test ci angle plus grand que 0, avant la conversions
			//if (betta_D > 0)
			//{
			//	betta_R = betta_D * (3.14 / 180); // Conver degré a rad
			//}
			break;
		}
	}
}

int Conversion_DegRad(int pt_strTriangle, struct str_triangleRectangle* pt_str)
{
	// Declaration des variable de fonction
	int i = 0;
	float alpha_R = 0;
	float alpha_D = 0;
	float betta_R = 0;
	float betta_D = 0;

	// Pour chargé les valeur que le user a choisis dans la variable
	for (i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 1:
			alpha_R = pt_str->tb_Angle[0];	// Le pointeur met la neuvelle valeur dans notre variable, depuis le tableux que on n'a pointé

			//// Test ci angle plus grand que 0, avant la conversions
			//if (alpha_R > 0)
			//{
			//	alpha_D = alpha_R * (180 / 3.14); // Conver rad en degré
			//}
			//break;

		case 2:
			alpha_D = pt_str->tb_Angle[1];

			// Test ci angle plus grand que 0, avant la conversions
			if (alpha_D > 0)
			{
				alpha_R = alpha_D * (3.14 / 180); // Conver degré a rad
			}
			break;

		case 3:
			betta_R = pt_str->tb_Angle[2];

			//// Test ci angle plus grand que 0, avant la conversions
			//if (betta_R > 0)
			//{
			//	betta_D = betta_R * (180 / 3.14); // Conver rad en degré
			//}
			//break;

		case 4:
			betta_D = pt_str->tb_Angle[3];

			// Test ci angle plus grand que 0, avant la conversions
			if (betta_D > 0)
			{
				betta_R = betta_D * (3.14 / 180); // Conver degré a rad
			}
			break;
		}
	}
}

int CaluculerAlllAngles(int pt_strTriangle, int str_triangleRectangle, int e_validation)
{
	// Declaration des variable de fonction
	//
	
	return e_validation;
}

int CaluculerLongeurSegment(int pt_strTriangle, int str_triangleRectangle, int e_validation)
{
	// Declaration des variable de fonction
	int Missing[3];

	//If missing 0 = c
	// c = a^2 + b^2
	// 
	//If missing 1 = a
	// a = c^2 - b^2
	// 
	//If missing 3 = b
	// b = c^2 - a^2

	return e_validation;
}

#endif // !CALCUL_TRIGO_H