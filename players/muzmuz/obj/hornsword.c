inherit "obj/weapon";

reset(arg) {
  if(arg) return;
     set_name ("Hornsword");
     set_alias ("sword");
     set_short ("Hornsword");
     set_long ("A Sword made of heavy horn, it looks like a very dangerous weapon.\n");
    set_class(20);
     set_weight(9);
     set_value(5000);
     set_alt_name ("hornsword");


}
init() {
  ::init();

}
