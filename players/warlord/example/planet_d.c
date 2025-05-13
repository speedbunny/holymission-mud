//  planet_d.c
//  (c) Dickhead Inc 1997
//  Just to have a daemon to control all the planets and its variables
// that change

#include <std.h>
#include <security.h>
#include "/wizards/rapture/includes/planet.h"

inherit "/wizards/rapture/classes/cPlanetClass";

private void vLoadPlanetInfo();
private void vSavePlanetInfo();

static void create() 
{
    ::create();  // Call to std daemon create()
    vLoadPlanetInfo();
}

**********************************************************************	
* 	Simple function to load all planet information on start up     *
**********************************************************************

private void vLoadPlanetInfo()
{
    seteuid(UID_DAEMONSAVE);
    if(!file_exists(PLANETS)) mPlanetInfo= ([ ]);
    else if(!mapp((mPlanetInfo =restore_variable(read_file(PLANETS)))))
	mPlanetInfo= ([]);
    seteuid(getuid());
} 

**********************************************************************	
* 	Simple function to save all planet information on changes      *
**********************************************************************

private void vSavePlanetInfo()
{
    seteuid(UID_DAEMONSAVE);
    writef_file(PLANETS, save_variable(mPlanetInfo), 1);
    seteuid(getuid());
}

**********************************************************************	
* 	Simple function to return the planet for referencing           *
**********************************************************************

nomask Planet cPlanetInfo( string sPlanet )
{
    return (Planet)mPlanetInfo[sPlanet];
}

**********************************************************************	
* 	Simple function to display all the planets existing            *
**********************************************************************
nomask string array aQueryPlanets()
{
    return keys(mPlanetInfo);
}

**********************************************************************	
* 	Simple function to return the size of a given planet           *
**********************************************************************
nomask int iQueryPlanetSize( string sPlanet )
{
    Planet cPlanet;
    if(!cPlanet=cPlanetInfo(sPlanet)) return 0;
    return cPlanet->iPlanetSize;
}
