/*
   the idea .. 
   memorizing killings and good deeds
   player([ "kill"  : ({ "namekill", "number" })
            "gdeed" : ({ "namehelp", "number" }) ])
*/
#include "/players/shadowmonk/include/defs.h"
#define FILE "/players/shadowmonk/etc/deed_area1"

mapping deeds;

status add_deed( string *data ) {
    deeds= ([]);
    restore_object( FILE );
    if( !deeds[ data[0] ] )
        deeds[ data[0] ] = ([]);
    if( !deeds[ data[0] ][ data[1] ] )
        deeds[ data[0] ][ data[1] ] = ([]);
    if( !deeds[ data[0] ][ data[1] ][ data[2] ] )
        deeds[ data[0] ][ data[1] ][ data[2] ] = 1;
    else deeds[ data[0] ][ data[1] ][ data[2] ]++;
    save_object( FILE );
    return 1;
}

void show_deeds() {
    int     i, is, j, js, k, ks, l, ls;
    string *indi, *indj, *indk;
    deeds= ([]);
    restore_object( FILE );
    for( i=0, is=sizeof( (indi=m_indices( deeds ) ) ); i<is; i++ ) {
        TME( indi[i] );
        for( j=0, js=sizeof( (indj=m_indices( deeds[indi[i]] ) ) ); j<js; j++ ) {
            TME( " "+indj[j] );
            for( k=0, ks=sizeof( (indk=m_indices( deeds[indi[i]][indj[j]] ) ) ); k<ks; k++ )
                TME( "  "+indk[k]+ " " + deeds[indi[i]][indj[j]][indk[k]] );
        }
    }
}

mapping query_deeds() {
    deeds= ([]);
    restore_object( FILE );
    return deeds;
}
    
void init() {
    add_action( "add", "add");
    add_action( "show", "show");
}

status add( string str ) {
    string *vars;
    vars = explode( str , " ");
    add_deed( ({ vars[0], vars[1], vars[2] }) );
    return 1;
}    

status show() {
    show_deeds();
    return 1;
}    
