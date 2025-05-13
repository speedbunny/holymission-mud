inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Nose");
    set_short("Nose");
    set_alias("nose");  
    set_gender(random(2));
    set_level(14);
    set_wc(13);
    set_ac(5);
    set_move_at_reset();
    set_long(
      "A gigantic nose hangs before you. Gobs of snot are plastered all over\n"
"the walls. Lenghy hairs hanging from it's opening blow freely in the breeze.\n"
"Beware the nose could erupt at anytyme!\n");
    load_chat(8,({ "'ACHOOoo!' The nose blows mucus all over you.\n",
        "Sorry about that. Anyone got a hanky?\n",
        "Anyone got a rubber nipple? I need to trim my hairs.\n",
      }));
}
