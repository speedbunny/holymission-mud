#include "/players/shadowmonk/include/defs.h"

// Defines;
#define VIRRMS          "virtualrooms"
#define BORRMS          "borderrooms"
#define CONNEC 	        "connections"
#define MAPNAME         "mapname"
#define INITIALX        "initialx"
#define INITIALY        "initialy"
#define UPDOWN          "updowncoordinates"
#define NUMBERS         "0123456789"
#define VIRRMSNICKS     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define BORRMSNICKS     "abcdefghijklmnopqrstuvwxyz"
#define MAXCOUNT        300
#define DIVCOUNT        25

// Variables;
private string  Master;
private string  MapFile;
private string  IniFile;

private mapping IniData;
//  IniData = ([
//      VIRRMS = ([
//          sSymbol : filename
//      ]);
//      BORRMS = ([
//          sSymbol : filename
//      ]);
//      CONNEC = ([
//          sSymbol : exitstring
//      ]);
//  ]);

private mapping MapData;
//  MapData = ([
//      MapLevel = ([
//          MAPNAME       : string
//          INITIALX      : integer;
//          INITIALY      : integer;
//          UPDOWN        : ([
//              "x,y," : ({
//                   "upstring",
//                   "downstring"
//              })
//          ])
//          Coordinate("x,y,nick") : ([
//              "exitstring" : "file/coordinates"
//          ])
//      ])
//  ])

int   COUNT;

// Functions;
void reset( int arg );
void init();

private status Filter( string FilterString );
nomask  status SetVirtualData( string myMapFile, string myIniFile );
private status SetupVirtualData();
private status MapIniFile();
private void   MapMapFile( mixed *Data );
private void   ProcessLine( mixed *Data );
private string EncodeCoor( int x, int y, int level, string nick );
private string *DecodeCoor( string Encoded );
private string RetrieveChar( string S, int P );

string RetrieveChar( string S, int P ) {
    if( strlen( S ) > P )
        return extract( S, P, P );
    return 0;
}

string EncodeCoor( int x, int y, int level, string nick ) {
    return ( ( (int)MapData[ level ][ INITIALX ] + x ) + "," +
             ( (int)MapData[ level ][ INITIALY ] + y ) + "," + nick );
}

string *DecodeCoor( string Encoded ) {
    string *saTemp;

    saTemp = explode( Encoded, "," );
    if( sizeof( saTemp ) != 3 )
        return ({});
    return saTemp;
}

status Filter( string FilterString ) {
    if( FilterString != "" )
    if( ( FilterString[0] != '/' ) &&
        ( FilterString[1] != '/' )  )
        return 1;
    return 0;
}

status MapIniFile() {
    int    i;
    string sTemp, Section, *saIni, *saTemp;

TME( "MapIniFIle" );
    if( !( sTemp = implode( explode( implode( explode( read_file( IniFile ), " " ), "" ), "//" ), "\n//" ) ) )
        return 0;
    saIni = filter_array( explode( sTemp, "\n" ), "Filter" );
    for( i = 0, Section = "", saTemp = ({}); i < sizeof( saIni ); i++, saTemp = ({}) ) {
        if( saIni[i][0] == '[' ) {
            Section = saIni[i];
            if( Section == "[" + VIRRMS +"]" )
                Section = VIRRMS;
            else if ( Section == "[" + BORRMS +"]" )
                Section = BORRMS;
            else if ( Section == "[" + CONNEC +"]" )
                Section = CONNEC;
        }
        else
            saTemp = explode( saIni[i], "=" );
        if( ( Section != "" ) && ( sizeof( saTemp ) == 2 ) )
        if( saTemp[1] != "" ) {
            if( !IniData[ Section ][ saTemp[0] ] )
                IniData[ Section ][ saTemp[0] ] = ({});
            IniData[ Section ][ saTemp[0] ] += ({ saTemp[1] });
        }
    }
    save_object( "/players/shadowmonk/virtual/data" );
    return 1;
}

string get_exit_string( string sSymbol, int k, int l ) {
    switch( sizeof( IniData[ CONNEC ][ sSymbol ] ) ) {
        case 2 :
            if( ( l > 0 ) || ( ( k == 0 ) && ( l == 0 ) ) )
                return IniData[ CONNEC ][ sSymbol ][0];
            return IniData[ CONNEC ][ sSymbol ][1];
            break;
        case 4 :
            if( ( k == 0 ) && ( l == 1 ) )
                return IniData[ CONNEC ][ sSymbol ][0];
            else if( ( k == 2 ) && ( l == 1 ) )
                return IniData[ CONNEC ][ sSymbol ][1];
            else if( ( k == 2 ) && ( l == -1 ) )
                return IniData[ CONNEC ][ sSymbol ][2];
            else if( ( k == 0 ) && ( l == -1 ) )
                return IniData[ CONNEC ][ sSymbol ][3];
            break;
    }
    return 0;
}

void ProcessLine( mixed *Data ) {
    int    k, l, iPos, iMapY, level;
    string *saTemp, sSymbol, coor;

    // TME( "ProcessLine()" );
    level  = (int)Data[2];
    iMapY  = (int)Data[3];
    saTemp = Data[4];
    iPos   = (int)Data[5]+2;
    COUNT ++;

    if( iPos < strlen( saTemp[1] ) ) {
        sSymbol = RetrieveChar( saTemp[ 1 ], iPos );
        if( ( !IniData[ VIRRMS ][ sSymbol ] ) &&
            ( !IniData[ BORRMS ][ sSymbol ] ) ) {
        if( COUNT < MAXCOUNT )
            if( COUNT % DIVCOUNT == 0 )
                call_out( "ProcessLine", 0, ({ Data[0], Data[1], level, iMapY, saTemp, iPos }) );
            else
                ProcessLine( ({ Data[0], Data[1], level, iMapY, saTemp, iPos }) );
            return;
        }
        coor = EncodeCoor( iPos/2, iMapY, level, sSymbol );
        if( !MapData[ level ][ coor ] )
            MapData[ level ][ coor ] = ([]);

        for( k = 0; k < 3; k++ )                  // index in array with 3 indexes
            for( l = - 1; l < 2; l++ ) {          // x value..
                sSymbol = RetrieveChar( (string)saTemp[ k ], iPos + l );
                if( !IniData[ CONNEC ][ sSymbol ] )
                    continue;
                MapData[ level ][ coor ] += ([ 
                    get_exit_string( sSymbol, k, l ) : EncodeCoor( iPos/2 + l, iMapY+k-1, level, "" )
                ]);
            }
        save_object( "/players/shadowmonk/virtual/data" );
        if( COUNT < MAXCOUNT )
            if( COUNT % DIVCOUNT == 0 )
                call_out( "ProcessLine", 0, ({ Data[0], Data[1], level, iMapY, saTemp, iPos }) );
            else
                ProcessLine( ({ Data[0], Data[1], level, iMapY, saTemp, iPos }) );
        return;
    }
    save_object( "/players/shadowmonk/virtual/data" );
    if( COUNT < MAXCOUNT )
        if( COUNT % DIVCOUNT == 0 )
            call_out( "MapMapFile", 0, ({ Data[0], Data[1], Data[2], Data[3] }) );
        else 
            MapMapFile( ({ Data[0], Data[1], Data[2], Data[3] }) );
    return;
}

void MapMapFile( mixed *Data ) {
    int    iLine, level, iMapY;
    string *saMap, sTemp, *saTemp;

    //TME( "MapMapFile()" );
    saMap = Data[0];    // the array with data;
    iLine = Data[1] +1; // line in the array;
    level = Data[2];
    iMapY = Data[3];    // y-value when in map;
    COUNT++;

    if( iLine < sizeof( saMap ) ) {
        TME( "sizeof(saMap) : " + sizeof(saMap) + " iLine : " + iLine + " level : " + level +" iMapY : " + iMapY );
        if( saMap[iLine][0] == '[' ) {
            TME( "samap[iline] [ : " + saMap[iLine] );
            sTemp = implode( explode( saMap[ iLine ], " " ), "" );
            sTemp = implode( explode( sTemp, "[" ), "" );
            sTemp = implode( explode( sTemp, "]" ), "" );
            saTemp = explode( sTemp, "," );
            if( sizeof( saTemp ) == 3 ) {
                level++;
                if( !MapData[ level ] )
                    MapData[ level ] = ([
                        MAPNAME  : saTemp[0],
                        INITIALX : saTemp[1],
                        INITIALY : saTemp[2],
                        UPDOWN   : ([])
                    ]);
            }
            else if( sizeof( saTemp ) == 4 ) {
                sTemp = saTemp[0] + "," + saTemp[1];
                if( !MapData[ level ][ UPDOWN ] )
                    MapData[ level ][ UPDOWN ] = ({});
                MapData[ level ][ UPDOWN ] += ([ sTemp : ({ saTemp[2], saTemp[3] }) ]);
            }
            else
                return;
            iMapY = -1;
            if( COUNT < MAXCOUNT )
                if( COUNT % DIVCOUNT == 0 )
                    call_out( "MapMapFile", 0, ({ saMap, iLine, level, iMapY }) );
                else
                    MapMapFile( ({ saMap, iLine, level, iMapY }) );
            return;
        }
        else if( strstr( NUMBERS, extract( saMap[iLine], 0, 0 ) ) > -1 ) {
            TME( "samap[iline] getal : " + iLine + " " +saMap[iLine] );
            iMapY++;
            sTemp = "";
            if( iLine > 0 )
                if( saMap[ iLine - 1 ] != "" )
                    if( saMap[ iLine - 1 ][0] == ' ' )
                        sTemp = saMap[ iLine - 1 ];
            saTemp = ({ sTemp, saMap[ iLine ] });
            if( iLine + 1 < sizeof( saMap ) )
                if( saMap[ iLine + 1 ] != "" )
                    if( saMap[ iLine + 1 ][0] == ' ' )
                        saTemp += ({ saMap[ iLine + 1 ] });
                    else
                        saTemp += ({ "" });
            if( COUNT < MAXCOUNT )
                if( COUNT % DIVCOUNT == 0 )
                    call_out( "ProcessLine", 0, ({ saMap, iLine, level, iMapY, saTemp, 0 }) );
                else
                    ProcessLine( ({ saMap, iLine, level, iMapY, saTemp, 0 }) );
            return;
        }
        MapMapFile( ({ saMap, iLine, level, iMapY }) );
        return;
    }
    TME( "DONE!" );
    save_object( "/players/shadowmonk/virtual/data" );
    return;
}

status SetupVirtualData() {
    string sTemp, *saTemp;

TME( "SetupVirtualData()" );
    if( !MapIniFile() )
        return 0;
    sTemp = implode( explode( read_file( MapFile ), "//" ), "\n//" );
    if( !( saTemp = filter_array( explode( sTemp, "\n" ), "Filter" ) ) )
        return 0;
    MapMapFile( ({ saTemp,     // the file in pieces in this array
                   -1,          // Line in the array
                   0,          // pos in line
                   0,          // Level
                   -1,          // y-value of map
    }) );
    return 1;
}

status SetVirtualData( string myMapFile, string myIniFile ) {

TME( "SetVirtualData()" );
    if( ( file_size( myMapFile ) >=0 ) &&
        ( file_size( myIniFile ) >=0 ) ) {
        MapFile = myMapFile;
        IniFile = myIniFile;
	SetupVirtualData();
        return 1;
    }
    return 0;
}

void reset( int arg ) {

TME( "Reset()" );
    if( arg )
        return;
    COUNT = 0;
    Master = "/"+file_name( this_object() );
    if( !MapData )
        MapData = ([]);
    if( !IniData )
        IniData = ([]);
    if( !IniData[ VIRRMS ] )
        IniData[ VIRRMS ] = ([]);
    if( !IniData[ BORRMS ] )
        IniData[ BORRMS ] = ([]);
    if( !IniData[ CONNEC ] )
        IniData[ CONNEC ] = ([]);
    if( COUNT < MAXCOUNT )
        if( COUNT % DIVCOUNT == 0 )
            SetVirtualData( "/players/shadowmonk/virtual/tm.map",
                            "/players/shadowmonk/virtual/tm.ini" );
}

status getrooms() {
    int     i, j, k ;
    string  *lvl, *indi, *val;
    mapping tmap, ttmap;
   
    TME( "MapData\n    |" );
    lvl = m_indices( MapData );
    
    for( i=0; i < sizeof( lvl ); i++ ) {
        tmap = MapData[ lvl[k] ];
        TME( "    |--mapname       : " + MapData[ lvl[k] ][ MAPNAME ]);
        TME( "    |--initialx      : " + MapData[ lvl[k] ][ INITIALX ]);
        TME( "    |--initialy      : " + MapData[ lvl[k] ][ INITIALY ]);
        TME( "    |--updown        ");
        indi = m_indices( ( ttmap = MapData[ lvl[k] ][ UPDOWN ] ) );
        for( j=0; j < sizeof( indi ); j++ ) {
            val = ttmap[ indi[j] ];
            for( k=0; k < sizeof( val ); k++ )
                TME( "    |    |--" + indi[j] + " : " + val[k] );
        }
        tmap = m_delete( tmap, MAPNAME );
        tmap = m_delete( tmap, INITIALX );
        tmap = m_delete( tmap, INITIALY );
        tmap = m_delete( tmap, UPDOWN );

        indi = m_indices( tmap );    // coordinaten..
        for( j=0; j < sizeof( indi ); j++ ) {
            TME( "    |--"+ indi[ j ] );
            val = m_indices( tmap[ indi[ j ] ] );
            for( k=0; k < sizeof( val ); k++ )
                TME( "    |    |--" + val[k] + " : " + tmap[ indi[ j ] ][val[k] ] );
        } 
    }
    return 1;
}

void init() {
    add_action( "getrooms", "getr");
    
TME( "INIT" );
}
