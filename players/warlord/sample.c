varargs int vQueryPopulation( string sPlanet, string sCont, string sCoun, sTown ) 
{
 string sKey;
 string array saKeys;
    int iRet;

// ******************Grabbing Towns population**********************************

    if(sTown)
        return (Town) (
			(Country) (
                       (Continent) (
                           (Planet) (mPlanet[sPlanet])->mContinent[sCont])
                       ->mCountry[sCoun])
                   ->mTown[sTown])
               ->population;

// ******************Grabbing Countries population******************************
  
  else if(sCoun) {
        saKeys = keys(Country) (
                       (Continent) (
                              (Planet) (mPlanet[splanet])->mContinent[sCont])
                          ->mCountry[sCoun])
                      ->mTown);
        foreach(sKey in saKeys)
            iRet += queryPopulation(sPlanet, sCont, sCoun, sKey);
        return iRet;
    }

// ******************Grabbing Continents population*****************************

    else if(sCont) {
        saKeys = keys((Continent) (
                          (Planet) (mPlanet[sPlanet])->mContinent[sCont])
                          ->mCountry);
        foreach(sKey in saKeys)
            iRet += queryPopulation(sPlanet, sCont, sKey);
        return iRet;
    }

// ******************Grabbing Planets population********************************

 else if(sPlanet) {
        saKeys = keys((Planet) (mPlanet[planet])->mContinent);
        foreach(sKey in saKeys)
            iRet += queryPopulation(sPlanet, sKey);
        return iRet;
    }
}
