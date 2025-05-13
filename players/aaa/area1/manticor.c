/* Completed 15.01.1995 */

inherit "/obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("manticore");
    set_short("A manticore");
    set_long("What a strange monster! It has a body like a lion, but its "+
         "head is a human's\nhead: grey-haired and long-bearded. You had never "+
         "believed in the existence of\nsuch monsters, but no dubt: this is a "+
         "MANTICORE! Its sharp claws and spiked tail\nterrify you.\n");
    set_gender(1);   
    load_a_chat(15,({"Manticore says: Come on, you wimp, let's see who is "+
        "stronger!\n","Manticore says: Drop your weapon and run away, "+
        "you weakling!\n"}));
    set_al(-500);
    set_level(20);
    set_chance(25);
    set_spell_dam(100);
    set_spell_mess1("The manticore swings his tail, and shoots a dozen of "+
                    "spikes at you!!!\n");
    set_spell_mess2("The manticore swings his tail, and shoots a dozen of "+
                    "spikes at you!!!\n");  
    set_race("manticore");
    set_aggressive(1);
    set_ac(10);
    set_wc(30);
    set_hp(2000);
    add_money(5000);
}     
