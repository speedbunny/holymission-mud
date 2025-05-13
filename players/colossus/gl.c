/* Bracers to heal appr wizards. If you clone it, you */
/* are responsible for whom you give it to!           */
/* Colossus                                           */

#define FILE "/players/colossus/gl.c:"
inherit "obj/armour";

string query_auto_load(){ return FILE; }

int drop(string str){
    if(id(str))
	return 1; 
}

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("gloves");
    set_short("Gloves of healing");
    set_long("Gloves of healing. Just type 'heal' to heal yourself.\n");
    set_type("gloves");
    set_value(0);
    set_ac(0);
    write_file("/players/colossus/private/GLOG",
      capitalize((string)this_player()->query_real_name())+
      " cloned bracers at " + ctime(time())+".\n");
}

void init(){
    ::init();
    add_action("heal", "heal");
}

status heal(){
    if((int)this_player()->query_level()>=30){
	this_player()->heal_self(150);
	write("You have been healed.\n");
	return 1;
    }
    else {
	write("You are not allowed to have this object.\n");
	write_file("/players/colossus/private/GLOG",
	  capitalize((string)this_player()->query_real_name())+
	  " tried to use bracers at "+ ctime(time()) +".\n");
	destruct(this_object());
	return 1;
    }
}

