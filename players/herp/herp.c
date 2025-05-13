inherit	"sys/god";

init() {
    level=1000;
    add_action("doit","doit");
}

reset(arg) {
  if (arg) return;

  /* The following MUST ONLY BE CALLED WHEN THE PLAYER LOGS ON !!! */

  cap_name = "";
  stats=allocate(6);
  sizes="obj/share"->share_armour_sizes(); /* shared memory array */
  set_size(3);
  hold_flag=0;
  arm_types="obj/share"->share_armour_types(); /* shared memory array */
  armour=allocate(sizeof(arm_types));
  rings=allocate(10);
  others=allocate(10);
  ring_cnt=other_cnt=0;
  hands = ({});                         /* init the array            */
  number_of_arms = 1;                   /* default for our arms (pat) */
  spell_time = -1;                      /* no spell to be released (pat) */

    level = 1000;
    name = "logon";
    cap_name = "Logon";
    real_size=0; 
    real_race=0;
    msgin = "arrives"; msgout = "leaves";
    mmsgin = "arrives in a puff of smoke";
    mmsgout = "disappears in a puff of smoke";
    title = "the title less";
    al_title = "neutral";
    real_al_title = al_title;
    gender = -1; /* Illegal value, so it will be changed! */
    env_var=([]);
    poisonname=explode("not/very/really","/");
    sanction_by=({ });
    sanction_to=({ });
    incognito=1;
    prompt="Huhu";

    releaseTime = -1;     /* pat (2505'93): no action to be released */
    actionVerb = "";      /* pat (2505'93): no action to be released */

}

doit() {
    exec(this_object(),this_player());
    write("Done.\n");
    return 1;
}
