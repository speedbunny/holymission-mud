/* So Goldwolf can entertain me without mixing with the game */
inherit "obj/treasure";
reset(arg) {
   ::reset(arg);

   if(!arg) {
      set_name("pencil");
      set_alias("pencil of creation");
      set_short("A multi-coloured pencil");
      set_long("It's almost alive with colours. \n"
             + "You feel the urge to draw something with it. \n");
      set_value(0);
      set_info("NOT for normal players!");
      }
   }

init() {
   ::init();
   add_action("draw","draw");
   }

draw(str) {
object obj;
   if(environment(this_object())->query_real_name()!="goldwolf") {
      write("This pencil is not for you! It turns to ashes... \n");
      destruct(this_object());
      return 1;
      }
   if(str=="stick") {
      obj=clone_object("/obj/torch");
      obj->set_name("stick");
      obj->set_short("A stick");
      obj->set_value(0);
      transfer(obj,this_player());
      return 1;
      }
   if(str=="torch") {
      obj=clone_object("/obj/torch");
      obj->set_value(0);
      transfer(obj,this_player());
      return 1;
      }
   if(str=="rope") {
      obj=clone_object("/obj/rope");
      obj->set_value(0);
      transfer(obj,this_player());
      return 1;
      }
   if(str=="chest") {
      obj=clone_object("/obj/container");
      obj->set_name("chest");
      obj->set_short("A chest");
      obj->set_value(0);
      transfer(obj,this_player());
      return 1;
      }
   if(str=="sword") {
      obj=clone_object("obj/weapon");
      obj->set_name("sword");
      obj->set_short("A sword");
      obj->set_value(0);
      transfer(obj,this_player());
      return 1;
      }
   if(str=="bag") {
      obj=clone_object("/obj/container");
      obj->set_name("bag");
      obj->set_short("A bag");
      obj->set_value(0);
      transfer(obj,this_player());
      return 1;
      }
   if(str=="knife") {
      obj=clone_object("/obj/weapon");
      obj->set_name("knife");
      obj->set_short("A knife");
      obj->set_value(0);
      transfer(obj,this_player());
      return 1;
      }
   if(str=="bottle") {
      obj=clone_object("/obj/drink");
      obj->set_value("fluid#Some fluid#GULP!#0#0#0");
      transfer(obj,this_player());
      return 1;
      }
   if(str=="horn") {
      obj=clone_object("/obj/weapon");
      obj->set_name("horn");
      obj->set_short("A horn");
      obj->set_value(0);
      transfer(obj,this_player());
      return 1;
      }
   if(str=="shield") {
      obj=clone_object("obj/armour");
      obj->set_name("shield");
      obj->set_short("A shield");
      obj->set_value(0);
      transfer(obj,this_player());
      return 1;
      }
   if(str=="remains" || str=="corpse") {
      obj=clone_object("obj/corpse");
      obj->set_name("some creature");
      transfer(obj,this_player());
      return 1;
      }
   if(str=="jacket") {
      obj=clone_object("/obj/armour");
      obj->set_name("jacket");
      obj->set_short("A jacket");
      obj->set_value(0);
      transfer(obj,this_player());
      return 1;
      }
   if(str=="axe") {
      obj=clone_object("obj/weapon");
      obj->set_name("axe");
      obj->set_short("An axe");
      obj->set_value(0);
      transfer(obj,this_player());
      return 1;
      }
   write("Somehow you can't make a good enough drawing of a "
       + str + ". \n");
   return 1;
   }
