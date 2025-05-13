state(arg) {
  int hascreatures, i;
  string line, silent, link;
  if(arg) return;
  if(raven) hascreatures = 1;
  for(i = 0; i < MAXCREATURES; i++)
    if(creatures[i]) hascreatures = 1;
  line = brooch->query_line();
  if(silent_move) silent = "ON";
  else silent = "OFF";
  write("Your current status:\n");
  write("  " + TP->SHORT + "\n");
  printf("    Brooch Talk: %-3s       Brooch Power: %d / %d\n",
	 line, brooch->BP, MAXBP);
  printf("    Creature Silence: %-3s  Hood Strength: %d\n",
	 silent, hoodlevel);
  if(!hascreatures) {
    write("    No Creatures under command.\n");
    return 1;
  }
  write("    Creatures under command:\n");
  if(raven) write("      Raven\n");
  for(i = 0; i < MAXCREATURES; i++)
    if(creatures[i])
      switch(creatures[i]->query_creature()) {
        case "wisp":
	  write("      Will-O-The-Wisp, light strength " +
		creatures[i]->query_ls() + "\n");
	  break;
	case "beast":
	  printf("      Beast of Burden,%5d / %-3dweight, %d coins\n",
		 creatures[i]->query_carried(),
		 creatures[i]->query_cap(),
		 creatures[i]->query_money());
	  break;
	case "seeker":
	  if(creatures[i]->query_link()) link = "ON";
	  else link = "OFF";
	  printf("      Seeker,%23s\n",
		 "Mindlink: " + link);
	  break;
	case "golem":
	  printf("      %-16s%5d / %-5d\n",
		 CAP(creatures[i]->query_golem_type()) + " Golem,",
		 creatures[i]->HP,
		 creatures[i]->MAXHP);
	  break;
	case "attacker":
	  printf("      %-16s%5d / %-5d\n",
		 creatures[i]->NAME + ",",
		 creatures[i]->HP,
		 creatures[i]->MAXHP);

	  break;
	default:
	  break;
      }
  return 1;
}
