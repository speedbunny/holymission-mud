inherit "obj/armour";

  reset(arg) {
  ::reset(arg);
  if (arg) return;
  
  set_name("");
  set_arm_light(-20);
  call_out("dest_me",20);
  }
  
  dest_me() {
    destruct(this_object());
    }
