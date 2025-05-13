inherit "obj/monster";
int follow_flag, chase_flag;

int done_flag;
object master;

string query_master(){
    if(master) return (string)master->query_name(); }
void set_master(object ob) { master=ob; }

void locked_up(){
    done_flag=1;
    chase_flag=1;
    follow_flag=1;
    master=0;
    remove_call_out("the_chase");
    remove_call_out("follow_on");
}

void init(){
    ::init();
    if(present("ARREST_WARRANT", this_player()) &&
      !chase_flag && !follow_flag){
	tell_room(environment(),
	  query_name()+" screams as "+
	  this_player()->query_name()+" enters.\n");
	tell_room(environment(),
	  query_name()+" screams: You will never take me alive!\n");
	remove_call_out("the_chase");
	call_out("the_chase", 3);
    }
}

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("nameless");
    set_alias("fugitive");
    set_alt_name("HOBBIT_FUGITIVE");
    set_level(10);
    set_gender(1);
    set_al(-80);
    set_long("This is a hobbit fugitive who's desperately running to escape\n"+
      "the authorities.\n");
    set_wc(10);
    set_hp(5000);
    set_ac(6);
    enable_commands();
}

void the_chase(){
    if(!master || !living(master)){
	chase_flag=0;
	done_flag=0;
	move_object(this_object(), "/players/colossus/mearth/shire/forest4");
	remove_call_out("the_chase");
	return;
    }

    if (done_flag) return;
    if (chase_flag < 5)
	tell_object(master, "You chase after the suspect.\n");
    if (!chase_flag) {
	chase_flag++;
	command("south", this_object());
	command("south", master);
	call_out("the_chase",2);
    }
    if (chase_flag == 1) {
	command("west", this_object());
	command("west", master);
	chase_flag++;
	call_out("the_chase",2);
    }
    if (chase_flag == 2) {
	command("west", this_object());
	command("west", master);
	chase_flag++;
	call_out("the_chase",2);
    }
    if (chase_flag == 3) {   
	command("east", this_object());
	command("east", master);
	chase_flag++;
	call_out("the_chase",2);
    }
    if(chase_flag==4){
	command("north", this_object());
	command("north", master);
	chase_flag++;
	call_out("the_chase",2);
    }
    if (chase_flag >= 5) {
	tell_room(environment(),
	  query_name()+" says: I give up... take me in!\n");
	remove_call_out("the_chase");
	follow_flag = 1;
	chase_flag = 0;
	done_flag = 1;
	call_out("follow_on", 2);
    }
}  
object captain;
void follow_on() {

    if (!master || !living(master) || !random(1000)) {
	tell_room(environment(),
	  query_name()+" runs back to his hideout.\n");
	move_object(this_object(), "/players/colossus/mearth/shire/forest4");
	remove_call_out("follow_on");
	chase_flag = 0;
	follow_flag = 0;
	master = 0;
	return;
    }
    captain = present("thain", environment());
    if (captain) {
	tell_room(environment(),
	  "Thain says: Well done! We finally caught the bastard!\n");
	tell_room(environment(),
	  "Thain yells: Guards!! Bring the prisoner to the cell!\n");
	captain->lock_up(this_object(), master);
	return;
    }     
    if (!present(master,environment())) {
	tell_room(environment(),
	  query_name()+" scurries away.\n");
	move_object(this_object(), environment(master));
	tell_room(environment(),
	  query_name()+" arrives.\n");
    }
    call_out("follow_on", 2);
} 

