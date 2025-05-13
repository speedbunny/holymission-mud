inherit "obj/monster";
object staff, coat;

void reset(int arg){
    ::reset(arg);
    staff=clone_object("obj/weapon");
    staff->set_name("staff");
    staff->set_short("A gnarled staff");
    staff->set_long("A gnarled staff used as a walking stick.\n");
    staff->set_class(7);
    staff->set_weight(1);
    staff->set_value(25);
    move_object(staff, this_object());
    set_name("gaffer");
    coat=clone_object("obj/armour");
    coat->set_name("coat");
    coat->set_short("A coat");
    coat->set_long("A knitted coat used by old hobbits.\n");
    coat->set_ac(1);
    coat->set_weight(1);
    coat->set_type("armour");
    coat->set_value(10);
    coat->set_size("small");
    move_object(coat, this_object());
    set_short("A hobbit gaffer");
    set_long("This is one of the elderly hobbits. He's a grandfather or gaffer\n"+
      "as the hobbits call him. Though he looks old he has seen his fights\n"+
      "in life and you think he is in good health still.\n");
    set_level(5);
    set_hp(80);
    set_race("hobbit");
    set_gender(1);
    set_size(2);
    command("wield staff", this_object());
    command("wear coat", this_object());
}
