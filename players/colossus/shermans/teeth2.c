/* Edited by Colossus 030394 */
/* Makes no sense using teeth as weapons, especially at */
/* such a high level. Best to use it as weapons but destruct */
/* it in monster_died function in the monster that uses the */
/* teeth */

#pragma strict_types

inherit "obj/weapon";

void reset(int arg){
    ::reset();
    set_name("teeth");
    set_class(18);
    set_weight(1);
    set_value(2000);
    set_type(2);
    set_short("Vampire teeth");
    set_long("Very long and sharp teeth.\n");
}

status query_teeth(){
    return 1;
}
