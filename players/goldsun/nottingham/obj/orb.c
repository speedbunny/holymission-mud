inherit "/obj/treasure";
#define TP this_player()

reset(arg){
 if (arg) return;
 set_name("bright orb");
 set_alias("orb");
 set_alt_name("goldsun_orb_rockland_door");
 set_value(12);
 set_weight(1);
 set_short("A bright orb");
 set_long("A bright orb made of glass. It is very hot.\n"); 
 set_light(1);
}

get(){
object r;

 r=present("special_d_ring",TP);
 if ( r && (r->query_quest()=="white_tower") && r->query_worn()) return 1;

 write("It is very hot orb. OUCH. It hurts you !\n");
 say(TP->query_name()+" tries to touch the orb.\n");
 TP->hit_player(22);
 return 0;
}

string query_quest(){ return "white_tower"; }

