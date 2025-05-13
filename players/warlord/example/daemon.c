varargs int iQueryPopulation( string sPlanet, string sCont, string sCoun, string sTown )
{
 string sKey;
 string array saKeys;
    int iRet;

// ******************Grabbing Towns population******************************

    if(sTown)
return (int)(Town)(Country)(Continent)mPlanetInfo[sPlanet]->mContinent[sCont]->mCountry[s
Coun]->mTown[sTown]->iPopulation;

// ******************Grabbing Countries population**************************

    else if(sCoun) {
        saKeys = keys(Country) (
                       (Continent) (
                      (Planet)(mPlanet[sPlanet])->mContinent[sCont])
                           ->mCountry[sCoun])
                       ->mTown);
        foreach(sKey in saKeys)
            iRet += iQueryPopulation(sPlanet, sCont, sCoun, sKey);
        return iRet;
    }

// ******************Grabbing Continents population*************************

    else if(sCont) {
        saKeys = keys((Continent) (
                        (Planet) (mPlanetInfo[sPlanet])->mContinent[sCont])
                          ->mCountry);
        foreach(sKey in saKeys)
            iRet += iQueryPopulation(sPlanet, sCont, sKey);
        return iRet;
    }

// ******************Grabbing Planets population****************************
   else if(sPlanet) {
        saKeys = keys((Planet) (mPlanet[planet])->mContinent);
        foreach(sKey in saKeys)
            iRet += iQueryPopulation(sPlanet, sKey);
        return iRet;
    }
}// End of iQueryPopulation
