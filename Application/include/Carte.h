#ifndef Carte_h
#define Carte_h
	
class Carte{

	//Attributs
	private:
		int id;
		
	//Constructeur et destructeur
	public:
		Carte(int r, int coul);
		~Carte();
		
	//Accesseurs
		int	getCouleur() 	const;
		int	getRang() 	const;
		int 	getId()		const;	

};

#endif