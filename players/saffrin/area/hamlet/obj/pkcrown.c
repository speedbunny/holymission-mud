inherit "/obj/armour";
     
reset(arg) {

  ::reset(arg);
  if (!arg) {    
      set_name("crown");
      set_short("Player King's crown");
      set_long("The is a  tin crown that is worn by the player king.  It has five triangular\n"+
                 "on its top.\n");
      set_ac(1);
      set_size(3);
      set_type("helmet");
      set_value(500);
      set_weight(1);
  }
}
