#define TP      this_player()
#define TO      this_object()

inherit "room/room";
object store_room;
int no_clean_up() {
  return 1;
}

void reset(int arg) {     
    if(!arg) {

        set_light(1);
        short_desc = "The Jedi Storage Room in the lower sanctums";     
        long_desc = "\
This room is where masters of the force can store equipment for the training \
jedi to borrow.   A small Ewok runs around, keeping the place neat and tidy, \
and he looks as if he would be more than happy to assist you if you needed help.  \
There is a counter here with a bell on it and a neatly engraved plaque hangs on \
the far wall. \n\n";

    property=({"no_telport","no_fight","no_steal"});

    smell="\nThe room smells freshly polished.\n";



        dest_dir = ({
            "/players/mangla/guild/rooms/corridor2",  "north",

        });


         items = ({
             "room", "A neat and tidy room, where you can store equipment",            
             "ewok", "A small Ewok, busying himself with keeping the place in order",
             "counter", "The counter stretches from wall to wall, and there are rows of cupboards behind it",       
             "cupboards", "Many cupboards where the Ewok keeps your items safe",
             "bell", "A shiny gold bell.  Perhaps you could 'ring' it?",
             "plaque", "There's something written on it.  Perhaps you could 'read' it?",
             
        });
    }
    ::reset(arg);
}

init() {
  ::init();
  add_action("_list","list");
  add_action("_borrow","borrow");
  add_action("_deposit","deposit");
  add_action("_read","read");
  add_action("_ring","ring");
}

set_store_room(ob) {
  store_room=ob;
  log_file("SHOPS",file_name(this_object())+" : "+ ob+"\n");
}

_list(str) {
 set_store_room("/players/mangla/guild/rooms/store");
  store_room->inventory(str);
  return 1;
}


_deposit(str) {

object ob,*in;
int i,do_destroy;

  set_store_room("/players/mangla/guild/rooms/store");
  if (!str) return;
  if (str=="all") {
     in=all_inventory(TP);
     for (i=0;i<sizeof(in);i++)
        if (!in[i]->drop() && in[i]->query_value()) do_sell(in[i]);
     write("Ok.\n");
     return 1;
  }
  if (!(ob=present(str,TP)) && !(ob=present(str,TO))) {
     write("No such item ("+str+") here.\n");
     return 1;
  }
  do_deposit(ob);
  return 1;
}

do_deposit(ob) {
int value,do_destroy;

  if (!(value=ob->query_value())) {
     write("The Ewok tells you: My master says I cannot keep "+ob->short()+" in here.\n");
     return 1;
  }
  if (ob->query_quest_item()) do_destroy=1;
  if (environment(ob)==TP) {
     int weight;
     if (ob->drop()) {
        write("The Ewok frowns and says: I can't take it from you.\n");
        return 1;
     }
     weight=ob->query_weight();
     if(!do_destroy) TP->add_weight(-weight);
  }
     say(TP->query_name()+" deposits "+ob->short()+".\n");

  if (do_destroy) {
     write("The Ewok says: You cannot leave such important things in here.\n");
     return 1;
  }
  write("The Ewok says: Thank you! I will look after it safely for you.\n");
  store_room->store(ob);
  return 1;
}

_borrow(str) {
/*
Like this?? It allows non-jedi (if they sneak past everthing) to deposit
stuff but not to borrow it back - heh heh 
*/
 
  if (!str) return;
  set_store_room("/players/mangla/guild/rooms/store");
  if (TP->query_ghost()) {
     write("The Ewok giggles and says: You have no body to carry items with you.\n");
     return 1;
  }
  if (this_player()->query_real_guild()!=4) {
        write("The Ewok says: You are not allowed to borrow from here!\n");
        this_player()->move_player("is moved#players/mangla/guild/room");
        return 1 ;
  }

  store_room->borrow(str);
  return 1;
}

int _read(string str) {

  switch(str) {
    case "plaque" :
    case "words" :
    case "sign" : 
      {
        write("Jedi are generous in nature, and this storage facility has been made available\n");
        write("so the masters of the force can leave items for the trainee Jedi and store valuables \n");
        write("whilst venturing around the realms. You can 'deposit' and 'borrow' items free of charge \n");
        write("here, and to see what is currently available, type 'list'.\n");
        return 1;
       }
    
    default :
      write("What do you want to read?\n");
      return 0;
  }
}

int _ring(string str) {

  switch(str) {
    case "bell" :
    case "golden bell" :
      {
        write("DING!!! DING!!!\n");
        write("The bell rings loudly!!!\n");
        write("The Ewok starts to scurry around in distress, looking nervous.\n");
        return 1;
       }
    
    default :
      write("What do you want to ring?\n");
      return 0;
  }
}

