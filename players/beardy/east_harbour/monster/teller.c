inherit "obj/npc";

reset(int arg) 
{ ::reset(arg);
  if(!arg) 
  {
    set_alt_name("sailor");
    set_race("human");

    set_long("This is the invisible storyteller of the ship :)\n");
    set_gender(1);

    set_level(1);
    set_hp(100000);

    load_chat(30,
        ({
           "You see a nice cloud in the sky.\n",
           "FIIIIUUUU ! A seagull crosses you way.\n",
           "You see the sea in all it's mystery.\n",
           "Splash ! A big wave rolls over the boat.\n",
           "Ah.. You feel the warm sun.\n",
           " You hear an inner voice : Go to Walhalla, go !\n",
           "Platsch ! A little fish sprung out of the water and in again.\n",
           "WUIII ! What a strong wind.\n",
           "Oh no ! There is absolutely no wind today.\n",
           "Ah there is a strong wind today. The speed is very fast.\n",
	   "What a beautiful blue sky...\n",
           "You hear an inner voice : Go to Walhalla, go !\n"
         }));
  }
}
