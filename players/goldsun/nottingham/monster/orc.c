
inherit "/obj/orc";
int hbc;
int count, delay;

#define TO this_object()
#define GATES "/players/goldsun/nottingham/room/gates"

void reset(int arg)
{
    string s;
    int i;

    ::reset(arg);

    load_a_chat(20, ({"Orc says: Kill @@do_objective@@!\n",
	"Orc says: Bloody @@do_races@@!\n",
	"Orc says: Stop @@do_objective@@!\n",
	"Orc says: Get @@do_objective@@!\n",
	"Orc says: Let's rip out @@do_possessive@@ guts!\n",
	"Orc says: Kill @@do_objective@@ before @@do_pronoun@@ runs away!\n",
	"Orc says: What is that @@do_race@@ doing here?\n"}));

    if (arg) return;
    set_short("An evil orc");
    set_wc(8);
    set_ac(3);
    set_hp(100);
    set_al(-12);
    set_aggressive(1);
    set_level(random(5)+1);
    set_size(2);
    if (sscanf(file_name(this_object()),"%s#%d",s,i)==2)
    {
        set_heart_beat(1);
        count = 10 + random(5);
        delay = 8;
    }
    set_dead_ob(TO);
}

void init()
{
    if (!delay && test_if_any_here())
    {
        delay = 8;
        set_heart_beat(1);
    }
    ::init();
}

void heart_beat() {
    string s;
    int i;

  ::heart_beat();
    count--;
    if (sscanf(file_name(TO), "%s#%d",s,i)==2 && count==0)
    {
	     random_move();
        count = 10 + random(5);
        delay--;
    }
    if (!delay)
        set_heart_beat(0);
}

void monster_died(object ob){
    GATES->add_enemy(-1);
}

int no_clean_up(){ return 1; }

