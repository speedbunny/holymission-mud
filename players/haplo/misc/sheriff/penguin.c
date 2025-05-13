inherit "obj/monster";
int count;

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("penguin");
    set_level(1);
    set_hp(999999);
    set_al(0);
    set_gender(1);
    set_race("penguin");
    set_short("A little penguin");
    set_long("A little penguin hugging a Bud Ice bottle.\n");
    set_wc(6);
    set_ac(5);
    set_aggressive(0);
    set_size(1);
    set_move_at_reset();
    load_chat(5, ({
	"The penguin sings: Doobie Doobie Doo...\n",
	"The penguin sings: Doobie Doobie Doo...\n",
	"The penguin acts innocent.\n",
	"The penguin hugs his Bud Ice tightly.\n",
      }) );
    move_object(clone_object("/players/exos/objects/bud_ice"),this_object());
}

heart_beat() {
    if(count++>4) {
	random_move();
	count=0;
    }
    ::heart_beat();
}
