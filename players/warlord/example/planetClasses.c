// Class for planets. May expand it for most space objects
//(c) Dickhead Inc. 1997 Sci Fi mud.
// Version 1.0 


class cPlanet
{	
	int     iPlanetSize;
	string  sPlanetName; 
	mapping mContinents;
	int	  iPopulation;
	mapping mCoordiates;   
}

class cContinent
{
	int     iSize;
	int     iPopulation;
	string  sName;
	mapping mCountries;
}

class cCountry
{
	int     iSize;
	int     iPopulation;
	string  sName;
	string  sPresident;
	mapping mTowns;
}

class cTowns
{
	int     iSize;
	int     iPopulation;
	string  sName;
	mapping mBuildings;
	string  sMayor;
}
	




