inherit "obj/weapon";

int renew_ob(string str) {
string *fname,obname;
object obj;
  if(!present(str,this_player())) {
    if(!present(str,environment(this_player()))) {
      notify_fail("The staff radiates a weak red light as it can't find the item.\n");
      return 0;
    }
  }
  if(!obj = present(str,this_player()))
      obj = present(str,environment(this_player()));
  if(obj->query_player()) {
    notify_fail("The staff casts red sparks as it refuses to renew a player.\n");
    return 0;
    }
  obname = file_name(obj);
  fname = explode(obname,"#");
  if(transfer(clone_object(fname[0]),this_player()))
    move_object(clone_object(fname[0]),environment(this_player()));
  destruct(obj);
  write("The staff sends a warm pulse through the area as the item is renewed.\n");
  return 1;
}

void try_quit() {
  tell_object(environment(),"Your staff disappears into another dimension.\n");
  destruct(this_object());
  return 0;
}

int get() {
  if(this_player()->query_real_name() != "uglymouth") {
    write("You push and pull, but the staff won't move an inch.\n");
    return 0;
    }
  return 1;
  }

int drop() { return 1; }

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("wizard's staff");
  set_alias("staff");
  set_alt_name("uglymouth's staff");
  set_short("A wizard's staff");
  set_long("A yew-wooden wizard's staff, runes are carved all over.\n");
  set_class(10);
  set_value(0);
  set_read("Uglymouth's personal rune is carved at the centre.\n");

  if((string)this_player()->query_real_name() != "uglymouth") {
    write("As you touch the staff, it vanishes.\n");
    destruct(this_object());
    return 0;
  }
}

void init() {
  ::init();
  add_action("renew_ob","renew");
  add_action("try_quit","quit");
  }
