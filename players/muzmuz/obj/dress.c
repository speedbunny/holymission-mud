inherit "/obj/armour";
  reset(arg) {
  ::reset();
    if(arg) return;

      set_name ("dress");
      set_alias ("wedding");
      set_short ("wedding dress");
      set_long ("This is a white lacy wedding dress made to complete the bride`s appeal.\n");
      set_ac (0);
      set_weight (0);
      set_size(3);
      set_type ("armour");

return 1;
}
