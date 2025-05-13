inherit "obj/armour";
  
   reset(arg) {
    ::reset(arg);
    if(arg) return;
      set_id("weddingring");
      set_alias("ring");
      set_short("A weddingring");
      set_long("A small golden ring, with the inscription:\n\n"+
                 "For ever in love with: "+this_player()->query_name()+"\n");
      set_type("weddingring");
      set_ac(0);
      set_value(0);
    }
/* Patched by James. 
query_auto_load() { return "/players/whisky/guild/obj/wring:"; }
*/
drop() { write("The ring shatters as it hits the ground.\n");
         destruct(this_object()); return 1; }
