inherit "/room/room";

#define SELF    0
#define OTHER   1
#define SELF1   2
#define OPPO1   3
#define OTHER1  4
#define SELF2   5
#define OTHER2  6
#define ADV     7

#define TP      this_player()
#define TPNT    this_player()->query_name_true()

mapping feelings, adverbs;

private void   init_feelings();
private void   init_adverbs();
private string substitute( string msg, object tp, object oppo, string adv );
private void   frog_curse( object kisser, object kissed );

void reset( int tick )
{
   if ( tick ) return;

   short_desc = "Feeling master";
   long_desc = "This is the master of the feelings.\n";
   set_light( 1 );

   init_feelings();
   init_adverbs();
}

void init()
{
   if ( !(this_player()->query_archwiz()) ) {
      this_player()->move_player( "quickly#/room/church" );
      return;
   }

   add_action( "exec_feeling", "smile" );
}

int exec_feeling( string f, string arg )
{
   string p, a, *expl, *msg, res;
   int    idx;
   object targ;

   // ----- handle special commands ---------------
   if ( f == "me" ) {
      say( "#"+TPNT+" "+arg+"\n",0,TP,"#Someone "+arg+"\n" );
      write( "You emote: "+TPNT+" "+arg+"\n" );
      return( 1 );
   }

   // ----- parse the arguments -------------------
   if ( arg ) expl = explode( arg, " " );
   else       expl = ({});
   msg = feelings[f];
   switch( sizeof( expl ) ) {
      case 0: 
         a = msg[ADV]; p = 0;
         break;
      case 1:
         idx = match_array( adverbs[expl[0][0]], expl[0] );
         if ( idx > -1 ) {
            a = adverbs[expl[0][0]][idx];
            p = 0;
         }
         else {
            a = msg[ADV];
            p = expl[0];
         }
         break;
      case 2:
         p = expl[0];
         idx = match_array( adverbs[expl[1][0]], expl[1] );
         if ( idx > -1 )
            a = adverbs[expl[1][0]][idx];
         else
            a = msg[ADV];
         break;
      default:
         write( "And fish can fly !\n" );
         return( 1 );
   }

   // ----- execute the feeling -----------------
   if ( !p || !msg[SELF1] ) {
      write( substitute( msg[SELF]+"\n", TP, 0, a ) );
      res = substitute( msg[OTHER], TP, 0, a )+"\n";
      say( TPNT+" "+res,0,TP,"Someone "+res );
   }
   else {
      targ = present(p,environment(TP));
      if ( targ && !(targ->is_invis_for(TP)) ) {
         write( substitute( msg[SELF1], TP, targ, a )+"\n" );
         res = substitute(msg[OPPO1],TP,targ,a)+"\n";
         if ( TP->is_invis_for( targ ) ) tell_object( targ,"Someone " + res );
         else tell_object( targ, TPNT+" "+res );
         res = substitute( msg[OTHER1], TP, targ, a )+"\n";
         say( TPNT+" "+res,targ,TP,"Someone "+res );
         if ( f=="kiss" )
            frog_curse(TP, targ);
      }
      else
         write( "Nobody here with such a name ...\n" );
   }

   return( 1 );
}

string substitute( string msg, object tp, object oppo, string a )
{
   string *expl;

   msg = sprintf( msg, a );
   if ( oppo ) {
      expl = explode( msg, "$o" );
      if ( sizeof( expl ) )
         if(oppo->query_name() )
         msg = implode( expl, oppo->query_name() );
         else msg = implode( expl, oppo->short());
   }
   expl = explode( msg, "$p" );
   if ( sizeof( expl ) )
      msg = implode( expl, tp->query_possessive() );
   expl = explode( msg, "$b" );
   if ( sizeof( expl ) )
      msg = implode( expl, tp->query_objective() );

   return( msg );
}

private void frog_curse( object kisser, object kissed )
{
   if ( !(kissed->query_race()=="frog" || kissed->query_frog()) ) return;
   if ( kisser->query_race()=="frog" || kisser->query_frog() ) return;

   kisser->frog_curse(1);
   say(TPNT+" turns into a frog !\n",0,kisser,"");
   if ( kissed->query_player() ) {
      kissed->frog_curse(0);
      say(TPNT+" stops being a frog !\n",0,kisser,"");
   }
}

string *all_feelings()
{
   return( m_indices( feelings ) );
}

void show_feelings()
{
   mixed  *idx;
   int    i, size;
   string res;

   res = "These are the socials from which you can choose:\n\n";
   idx = m_indices( feelings );
   idx = sort_array( idx, "feelings_sort", this_object() );
   size = m_sizeof( feelings );
   res += idx[0];
   for ( i = 1; i < size; i++ )
      res += (", "+idx[i] );

   printf( "%-=*s\n", 78, res );
}

int feelings_sort( string ob1, string ob2 )
{
   if ( ob1 > ob2 ) return( 1 );
   return( 0 );
}

void show_adverbs()
{
   mixed  *idx, *val;
   int    i, j, mi, mj;
   string res;

   res = "These are the adverbs from which you can choose:\n\n";
   idx = m_indices( adverbs );
   idx = sort_array( idx, "adv_sort", this_object() );
   mi = m_sizeof( adverbs );
   for ( i = 0; i < mi; i++ ) {
      val = adverbs[idx[i]];
      mj = sizeof( val );
      for ( j = 0; j < mj; j++ )
         res += (val[j]+", ");
   }

   TP->more_string( sprintf( "%-=*s\n", 78, res ) );
}

int adv_sort( int ob1, int ob2 )
{
   if ( ob1 > ob2 ) return( 1 );
   return( 0 );
}

void init_adverbs()
{
    adverbs = ([ 'a': 
	      ({ "absentmindedly","affectionately","aimlessly","amazedly",
		 "amusedly","angrily","annoyedly","anxiously","apologetically",
		 "appreciatively","astonishedly"}),
		 'b':
	      ({ "badly","bashfully","bitterly","boredly","bouncily","briefly",
		 "brightly","broadly","busily" }),
                 'c':
	      ({ "carefully","charmingly","childishly","cluelessly","coldly",
		 "completely","confidently","confusedly","contemptuously",
		 "contendedly","crazily","cunningly","curageously","cutely",
		 "curiously","cynically" }),
		 'd':
	      ({ "dangerously","deeply","demonically","depressively",
		 "desperately","devilishly","dirtily","disappontedly",
		 "disgustedly","dreamily","doubtfully","drunkily" }),
		 'e':
              ({ "eagerly","egocentrically","egoisitically",
                 "endearingly","enthuisiastically","erotically",
                 "evilly","excitedly","exhaustedly" }),
		 'f':
	      ({ "fanatically","fatherly","fiercefully","firmly",
  		 "flirtatiously","fondly","foolishly","friendly",
		 "funnily","furtively" }),
		 'g':
	      ({ "gently","gigglishly","gleefully","gracefully","graciously"}),
		 'h':
	      ({ "happily","harmonically","heartbrokenly","heavily",
		 "helpfully","helplessly","honestly","hopefully","hornily",
		 "hungrily","hysterically" }),
	         'i':
	      ({ "ignorantly","impatiently","inanely","innocently",
		 "inquiringly","insanely","instantly","intently",
		 "interestedly","inwardly","irritatedly",
		 "ironically" }),
	         'j':
	      ({ "jealously","joyfully" }),
		 'k':
	      ({ "kindly","knowingly" }),
		 'l':
	      ({ "lazily","longingly","loudly","lovingly","lustfully" }),
		 'm':
	      ({ "madly","maniacally","melancholically","merrily",
		 "masterfully","mischievously","musically" }),
		 'n':
	      ({ "nastily","naughtily","nervously","nicely","noisily",
		 "nonchalantly" }),
		 'o':
	      ({ "obviously" }),
		 'p':
	      ({ "painfully","passionately","patiently","patronizingly",
		 "perfectly","personally","petulantly","physically",
		 "playfully","politely","proudly","professionally",
		 "profoundly","profusely" }),
		 'q':
	      ({ "questinoningly","quickly","quietly" }),
		 'r':
              ({ "randomly","rapidly","really","rebelliously","relievedly",
                 "roguishly","rudely" }),
		 's':
	      ({ "sadly","sadistically","sarcastically","satanically",
	 	 "scornfully","searchingly","secretly","seductively",
		 "sensually","sensuously","seriously",
		 "sexily","shamelessly","sheepishly","shyly","sickly",
		 "silently","skilfully","sleepily","slightly","slowly","slyly",
		 "smilingly","smoochily","softly","solemnly","speechlessly",
		 "strangely","stupidly","suggestively","suddenly",
		 "sweetly" }),
		 't':
	      ({ "tearfully","teasingly","tenderly","terribly","thankfully",
		 "theoretically","thoughtfully","tightly","tiredly",
		 "tragically","truly","trustfully" }),
		 'u':
	      ({ "unexpectedly","unhappily","unknowingly" }),
		 'v':
	      ({ "viciously","vigorously","virtually" }),
		 'w':
	      ({ "warmly","weakly","wearily","wholeheartedly","wickedly",
		 "wildly","wisely","wistfully","wryly" }),
		 'x':
	      ({ }),
		 'y':
	      ({ }),
		 'z':
	      ({ }),
		]);
}

void init_feelings()
{
   feelings = ([
      "me":
         ({ "special"
         }),
      "applaud":
         ({ "You applaud %s.",
            "applauds %s.",
            "You %s applaud $o.",
            "%s applauds you.",
            "%s applauds $o.",
            0,
            0,
            "wholeheartedly"
         }),
      "agree":
         ({ "You agree %s.",
            "agrees %s.",
            "You %s agree to $o.",
            "%s agrees to you.",
            "%s agrees to $o.",
            0,
            0,
            "wholeheartedly"
         }),
      "ack":
         ({ "Ack !",
            "goes ack !",
            0,
            0,
            0,
            0,
            0,
            0
         }),
      "blush":
         ({ "You blush %s.",
            "blushes %s.",
            0,
            0,
            0,
            0,
            0,
            "innocently"
         }),
      "beg":
         ({ "You %s beg for good fortune.",
            "%s begs for good fortune.",
            "You %s beg $o for good fortune.",
            "%s begs you for good fortune.",
            "%s begs $o for good fortune.",
            0,
            0,
            "desperately"
         }),
      "bounce":
         ({ "B O I N G !!!  You bounce %s.",
            "bounces %s.",
            0,
            0,
            0,
            0,
            0,
            "energetically"
         }),
      "brighten":
         ({ "You think about it, then it dawns to you. Your face brightens !",
            "thinks hard, then it dawns on $b, whose face brightens !",
            0,
            0,
            0,
            0,
            0,
            0
         }),
      "bow":
         ({ "You bow %s",
            "bows %s",
            "You bow %s to $o.",
            "bows %s to you.",
            "bows %s to $o.",
            0,
            0,
            "gracefully"
         }),
      "burp":
         ({ "You burp %s. Excuse yourself !",
            "burps %s",
            "You burp %s at $o.",
            "burps %s at you.",
            "burps %s at $o.",
            0,
            0,
            "rudely"
         }),
      "cackle":
         ({ "You throw back your head and cackle %s.",
            "throws back $p head and cackles %s.",
            "You throw back your head and cackle %s at $o.",
            "throws back $p head and cackles %s at you.",
            "throws back $p head and cackles %s at $o.",
            0,
            0,
            "gleefully"
         }),
      "cheer":
         ({ "You cheer %s.",
            "cheers %s.",
            "You cheer %s at $o.",
            "cheers %s at you.",
            "cheers %s at $o.",
            0,
            0,
            "enthusiastically"
         }),
      "chuckle":
         ({ "You chuckle %s.",
            "chuckles %s.",
            "You chuckle %s at $o.",
            "chuckles %s at you.",
            "chuckles %s at $o.",
            0,
            0,
            "politely"
         }),
      "clap":
         ({ "You clap %s.",
            "claps %s.",
            "You clap %s at $o.",
            "claps %s at you.",
            "claps %s at $o.",
            0,
            0,
            "briefly"
         }),
      "comfort":
         ({ "You %s comfort all around here.",
            "%s comforts all around here.",
            "You %s comfort $o.",
            "%s comforts you.",
            "%s comforts $o.",
            0,
            0,
            "sadly"
         }),
      "confused":
         ({ "You %s try to think, but fail.",
            "%s tries to think, but fails.",
            0,
            0,
            0,
            0,
            0,
            "desperately"
         }),
      "congratulate":
         ({ "You %s congratulate the whole world !",
            "%s congratulates the whole world !",
            "You %s congratulate $o.",
            "%s congratulates you.",
            "%s congratulates $o.",
            0,
            0,
            "honestly"
         }),
      "cough":
         ({ "You cough %s.",
            "coughs %s",
            "You %s cough at $o.",
            "%s coughs at you.",
            "%s coughs at $o.",
            0,
            0,
            "noisily"
         }),
      "cry":
         ({ "Waaaaaah !",
            "bursts into tears.",
            "You %s lean at $o's shoulder and cry bitterly.",
            "%s leans at your shoulder and cries bitterly.",
            "%s leans at $o's shoulder and cries bitterly.",
            0,
            0,
            "sadly"
         }),
      "cuddle":
         ({ "Don't you want to cuddle anyone particular ?",
            "looks for somebody to cuddle, seek shelter !",
            "You %s cuddle $o.",
            "%s cuddles you.",
            "%s cuddles $o.",
            0,
            0,
            "dreamily"
         }),
      "curse":
         ({ "You swear %s for quite a long time.",
            "%s swears: #@@*&^*$#^@! !!!!!",
            "You %s curse $o.",
            "%s curses you.",
            "%s curses $o.",
            0,
            0,
            "loudly"
         }),
      "curtsey":
         ({ "You curtsey %s.",
            "curtseys %s.",
            "You curtsey %s to $o.",
            "curtseys %s to you.",
            "curtseys %s to $o.",
            0,
            0,
            "gracefully"
         }),
      "cringe":
         ({ "You cringe in terror !",
            "cringes in terror !",
            "You %s cringe away from $o !",
            "%s cringes away from you !",
            "%s cringes way from $o !",
            0,
            0,
            "fearfully"
         }),
      "dance":
         ({ "Feels silly, doesn't it ?",
            "does the disco duck.",
            "You %s sweep $o across the dance floor !",
            "%s sweeps you across the dance floor !",
            "%s sweeps $o across the dance floor !",
            0,
            0,
            "happily"
         }),
      "die":
         ({ "You fall down, acting dead ?",
            "rolls over and does $p best to look dead.",
            0,
            0,
            0,
            0,
            0,
            "happily"
         }),
      "dream":
         ({ "You stare at the sky, dreaming of your own island ...",
            "stares at the sky, completely lost in $p dreams ...",
            0,
            0,
            0,
            0,
            0,
            0
         }),
      "duh":
         ({ "Uh, duhh... Feeling stupid, eh ?",
            "goes duhh, must be feeling stupid.",
            0,
            0,
            0,
            0,
            0,
            0
         }),
	"eeks":
         ({ "EEKS!  OH MY GOSH!",
            "goes eeks.",
            0,
            0,
            0,
            0,
            0,
            0
            }),
	"excuse":
         ({ "You %s excuse yourself.",
            "begs your pardon.",
            "You %s excuse yourself to $o.",
            "begs your pardon for $p actions.",
            "begs forgiveness from $o.",
            0,
            0,
            "kindly",
             }),
      
         "eyebrow":
         ({ "You %s raise an eyebrow.",
            "raises an eyebrow.",
            "You %s raise an eyebrow at $o.",
            "%s raises an eyebrow at you.",
            "%s raises an eyebrow at $o.",
            0,
            0,
            "inquiringly"
         }),
       "fart":
         ({ "You %s let off a real rip-roarer.",
            "%s lets off a real rip-roarer.",
            0,
            0,
            0,
            0,
            0,
            "rudely"
         }),
       "flip":
         ({ "You flip head over heels!",
            "flips head over heels!",
            0,
            0,
            0,
            0,
            0,
            0
         }),
       "flabergast":
         ({ "You fall to your knees completly flabergasted.",
            "falls to $p knees, completly flabergasted.",
            0,
            0,
            0,
            0,
            0,
            0
         }),
       "french":
         ({ "You search around desparatly for someone to kiss.",
            "is apparently confused about who to kiss.",
            "You give $o a deep and passionate kiss... seems to take forever",
            "gives you a deep and passionate kiss... seems to take forever",
          "gives $o a deep and passionate kiss, you fall asleep watching them",
            0,
            0,
            0
         }),
       "frown":
         ({ "You %s frown.",
            "%s frowns.",
            "You %s frown at $o.",
            "%s frowns at you.",
            "%s frowns at $o.",
            0,
            0,
            "annoyedly"
         }),
       "fume":
         ({ "You fume %s.",
             "fumes %s.",
             "You fume %s at $o.",
             "fumes %s at you.",
             "fumes %s at $o.",
             0,
             0,
             "angrily"
          }),
       "gasp":
        ({ "You gasp in astonishment!",
            "gasps in astonishment!",
            0,
            0,
            0,
            0,
            0,
            0
         }),
       "greet":
         ({ "You raise your hand in greeting to everyone.",
            "raises $p hand in greeting to everyone.",
            "You raise your hand in greeting to $o.",
            "raises $p hand in greeting to you.",
            "raises $p hand in greeting to $o, totally ignoring you.",
            0,
            0,
            0
         }),
       "giggle":
         ({ "You giggle %s.",
            "giggles %s.",
            0,
            0,
            0,
            0,
            0,
            "inanely"
         }),
       "glare":
         ({ "You glare %s at everyone in the room.",
            "glares %s at everyone.",
            "You glare %s at $o.",
            "glares %s at you.",
            "glares %s at $o.",
            0,
            0,
            "menacingly",
         }),
       "grin":
         ({ "You grin %s.",
            "grins %s.",
            "You grin %s at $o.",
            "grins %s at you.",
            "grins %s at $o.",
            0,
            0,
            "evilly"
         }),
       "groan":
         ({ "You groan %s.",
            "groans %s.",
            0,
            0,
            0,
            0,
            0,
            "loudly"
         }),
       "grope":
         ({ "You search around for someone to grope",
            "searches around for someone to grope.",
            "You %s grope $o.",
            "gropes you %s.",
            "gropes $o %s.",
            0,
            0,
            "lustfully"
         }),
       "growl":
         ({ "You growl %s.",
            "growls %s.",
            "You growl %s at $o.",
            "growls %s at you.",
            "growls %s at $o.",
            0,
            0,
            "angrily"
         }),
       "hiccup":
         ({ "You hiccup.",
            "hiccups.",
            0,
            0,
            0,
            0,
            0,
            0
         }),
       "hop":
         ({ "You %s hop around.",
            "%s hops around.",
            "You hop on $o and beg for a piggyback ride!",
            "hops on your back, and demands a piggyback ride!",
            "hops on $o's back and demands a piggyback ride.",
            0,
            0,
            "happily"
         }),
       "hug":
         ({ "You look around for someone to hug.",
            "looks around for someone to hug.",
            "You hug $o.",
            "hugs you.",
            "hugs $o.",
            0,
            0,
            0
         }),
       "kick":
         ({ "Oiff! You kick yourself in the spleen.",
            "kicks himself in the spleen.",
            "You %s kick $o.",
            "kicks you %s.",
            "kicks $o %s.",
            0,
            0,
            "angrily"
         }),
       "kiss":
         ({ "You %s kiss yourself.",
            "begins to act rather strangely.",
            "You %s kiss $o.",
            "%s kisses you.",
            "%s kisses $o.",
            0,
            0,
            "tenderly"
         }),
       "knee":
         ({ "You somehow manage to knee yourself in the groin.",
            "somehow manages to drive $p knee into $p groin and doubles over.",
           "You raise your knee into the groin of $o, $o doubles over in pain.",
            "suddenly raises $p knee into your groin. You gasp for air!",
            "raises $p knee into $o's groin sending $o sprawling to the floor.",
            0,
            0,
            0
         }),
       "laugh":
         ({ "You fall down laughing %s.",
            "falls down laughing %s.",
            "You laugh at $o.",
            "laughs at you.",
            "laughs at $o.",
            0,
            0,
            "hysterically"
         }),
       "lick":
         ({ "You search around for someone to lick.",
            "searches around for someone to lick.",
            "You lick $o %s.",
            "licks you %s.",
            "licks $o %s.",
            0,
            0,
            "lustfully"
         }),
       "love":
         ({"You search around for someone to show your affection towards.",
            "searches around for someone to show $p affections towards.",
            "You tell $o your true feelings.",
            "whispers to you sweet words of love.",
            "whispers in $o's ear. $o giggles.",
            0,
            0,
            0
         }),
       "moan":
         ({ "You moan %s.",
            "moans %s.",
            0,
            0,
            0,
            0,
            0,
            "loudly"
         }),
       "nibble":
         ({ "You nibble on your fingernails.",
            "nibbles $p fingernails.",
            "You %s nibble on $o's earlobe.",
            "%s nibbles on your earlobe.",
            "%s nibbles on $o's earlobe.",
            0,
            0,
            "playfully"
         }),
       "nuzzle":
         ({ "You search around for someone to nuzzle.",
            "searches around for someone to nuzzle.",
            "You %s nuzzle $o's neck.",
            "%s nuzzles your neck.",
            "%s nuzzles $o's neck.",
            0,
            0,
            "lovingly"
         }),
       "no":
         ({ "You shake your head no.",
            "shakes $p head no.",
            0,
            0,
            0,
            0,
            0,
            0
         }),
       "nod":
         ({ "You nod %s.",
            "nods %s.",
            "You %s nod to $o.",
            "%s nods to you.",
            "%s nods to $o.",
            0,
            0,
            "solemnly"
         }),
       "oops":
         ({ "OOPS!",
            "messed up, oops!",
            0,
            0,
            0,
            0,
            0,
            0
         }),
       "panic":
         ({ "P A N I C !!!!",
            "panics and searches for a place to hide.",
            0,
            0,
            0,
            0,
            0,
            0
         }),
       "ponder":
         ({ "You %s ponder the situation.",
            "%s ponders the situation.",
            "You %s ponder $o's last statement.",
            "%s ponders your last statement.",
            "%s ponders $o's last statement.",
            0,
            0,
            "carefully"
         }),
       "poke":
         ({ "You look around for someone to poke.",
            "searches around for someone to poke.",
            "You poke $o in the ribs.",
            "pokes you in the ribs.",
            "pokes $o in the ribs.",
            0,
            0,
            0
         }),
       "point":
         ({ "You %s point around.",
            "%s points around.",
            "You %s point at $o.",
            "points at you.",
            "%s points at $o.",
            0,
            0,
            "excitedly"
         }),
       "pout":
         ({ "You pout %s.",
            "pouts %s.",
            "You pout %s at $o.",
            "pouts %s at you.",
            "pouts %s at $o.",
            0,
            0,
            "cutely"
         }),
       "puke":
         ({ "You %s blow chunks all over the room.",
            "%s blows chunks all over the room.",
            "You %s vomit on $o.",
            "spews all over you. Disgusting",
            "loses $p lunch on $o.",
            0,
            0,
            "violently"
         }),
       "purr":
         ({ "You purr %s.",
            "purrs %s.",
            0,
            0,
            0,
            0,
            0,
            "softly"
         }),
       "rolleyes":
         ({ "You roll your eyes in exasperation.",
            "rolls $p eyes in exasperation.",
            0,
            0,
            0,
            0,
            0,
            0
         }),
       "ruffle":
         ({ "You want to ruffle whose hair?",
            "%s looks very confused.",
            "You %s ruffle $o's hair.",
            "%s ruffles your hair.",
            "%s ruffles $o's hair.",
            0,
            0,
            "playfully"
         }),
       "scream":
         ({ "You scream %s.  AAAAARRRRRRRRRGGGGGGGGGHHHHHH!",
            "screams %s.",
            "You scream %s at $o.",
            "screams %s at you.",
            "screams %s at $o.",
            0,
            0,
            "loudly"
         }),
       "scratch":
         ({ "You scratch your head %s.",
            "scratches $p head %s.",
            "You scratch $o's back. $o moans in satisfaction.",
            "scratches your back.  You say: higher! no lower!",
            "scratches $o's back.  $o arcs $p back in delight.",
            0,
            0,
            "inquisitivily"
         }),
       "shake":
         ({ "You are shaking in your boots!",
            "is shaking in $p boots!",
            "You %s shake hands with $o.",
            "%s shakes hands with you.",
            "shakes hands with $o.",
            0,
            0,
            "formally"
         }),
       "shiver":
         ({ "A tingling feelings goes up your spine.",
            "shivers like a bowl of jelly.",
            0,
            0,
            0,
            0,
            0,
            0
         }),
       "shrug":
         ({ "You shrug %s.",
            "shrugs %s.",
            0,
            0,
            0,
            0,
            0,
            "helplessly"
         }),
       "sigh":
         ({ "You sigh %s.",
            "sighs %s.",
            0,
            0,
            0,
            0,
            0,
            "deeply"
         }),
       "sing":
         ({"You start to sing, sing, Sing!",
            "starts to sing. Run away!",
            "You seronade $o with an empassioned melodey.",
            "sings a beatiful melody to win your heart.",
            "sings to $o. Must be trying to get laid.",
            0,
            0,
            0
         }),
       "slap":
         ({ "You slap yourself!",
            "slaps $pself. Doesn't that look silly?",
            "You slap $o %s.",
            "%s slaps you!",
            "slaps $o %s.",
            0,
            0,
            "viciously"
         }),
       "smirk":
         ({ "You smirk.",
            "smirks.",
            0,
            0,
            0,
            0,
            0,
            0
         }),
       "smile":
         ({ "You smile %s.",
            "smiles %s.",
            "You smile %s at $o.",
            "smiles %s at you.",
            "smiles %s at $o.",
            0,
            0,
            "happily"
         }),
       "snap":
         ({ "You snap your fingers.",
            "snaps $p fingers.",
            0,
            0,
            0,
            0,
            0,
            0
         }),
       "sneeze":
         ({ "GESUNDHEIT!",
            "sneezes %s.",
            0,
            0,
            0,
            0,
            0,
            "violently"
         }),
       "snicker":
         ({ "You snicker %s.",
            "snickers %s.",
            0,
            0,
            0,
            0,
            0,
            "amusedly"
         }),
       "sniff":
         ({ "You sniff %s.",
            "sniffs %s.",
            "You sniff $o.",
            "sniffs you.",
            "sniffs $o.",
            0,
            0,
            "sadly"
         }),
       "snore":
         ({ "You snore %s.",
            "snores %s.",
            0,
            0,
            0,
            0,
            0,
            "loudly"
         }),
       "snuggle":
         ({ "You search around for someone to snuggle.",
            "searches around for someone to snuggle.",
            "You %s snuggle up to $o.",
            "%s snuggles up to you.",
            "%s snuggles up to $o.",
            0,
            0,
            "gently"
         }),
       "spit":
         ({ "You %s spit on the ground.",
            "%s spits on the ground.",
            "You %s spit in $o's face.",
            "%s spit in your face.",
            "%s spits in $o's face.",
            0,
            0,
            "rudely"
         }),
       "squeeze":
         ({ "You squeeze your butt cheeks together.",
            "squeezes $p butt cheeks tight.",
            0,
            "You %s squeeze $o.",
            "%s squeezes you.",
            "squeezes $o %s.",
            0,
            0,
            "tightly"
         }),
       "stare":
         ({ "You stare off into space.",
            "stares off into space.",
            "You stare %s at $o.",
            "stares %s at you.",
            "stares %s at $o.",
            0,
            0,
            "intently"
         }),
       "strut":
         ({ "You strut your stuff!",
            "struts %s.",
            0,
            0,
            0,
            0,
            0,
            "proudly"
         }),
       "sulk":
         ({ "You %s sulk in the corner.",
            "%s sulks in the corner.",
            0,
            0,
            0,
            0,
            0,
            "pitifully"
         }),
       "stomp":
         ({ "You stomp your feet %s on the ground.",
            "stomps $p feet %s on the ground.",
            "You cackle with glee as you stomp on $o's foot.",
            "stomps on your foot, and cackles with glee.",
            "stomps on $o's foot, cackling to $bself.",
            0,
            0,
            "angrily"
         }),
       "stretch":
         ({ "You stretch your tired body.",
            "stretches $p tired body.",
             0,
            0,
            0,
            0,
            0,
            0
         }),
       "tap":
         ({ "You tap your foot %s.",
            "taps $p foot %s.",
            0,
            0,
            0,
            0,
            0,
            "impatiently"
         }),
       "tongue":
         ({ "You %s stick your tongue out at everyone.",
            "sticks $p tongue out at everyone.",
            "You stick your tongue out at $o.",
            "sticks $p tongue out at you.",
            "sticks $p tongue out at $o.",
            0,
            0,
            "mischieviously"
         }),
       "think":
         ({ "You try to look thoughtful but fail.",
            "tries to look thoughtful but fails.",
            0,
            0,
            0,
            0,
            0,
            0
         }),
       "thank":
         ({ "You thank yourself for a job well done.",
            "thanks $pself for a job well done.",
            "You %s thank $o.",
            "%s thanks you.",
            "%s thanks $o.",
            0,
            0,
            "graciously"
         }),
       "thump":
         ({ "You thump around the room.",
            "thumps around the room.",
            0,
            0,
            0,
            0,
            0,
            "merrily"
         }),
       "tickle":
         ({ "You try and tickle yourself %s.",
            "looks silly trying to %s tickle $pself.",
            "You %s tickle $o.",
            "%s tickles you!",
            "%s tickles $o.",
            0,
            0,
            "mercilessly"
         }),
       "twiddle":
         ({ "You %s twiddle your thumbs.",
            "%s twiddles $p thumbs.",
             0,
            0,
            0,
            0,
            0,
            "patiently"
         }),
       "wave":
         ({ "You wave farewell.",
            "waves farewell.",
            "You wave %s to $o.",
            "waves %s to you.",
            "waves %s to $o.",
            0,
            0,
            "happily"
         }),
       "whistle":
         ({ "You whistle %s.",
            "whistles %s.",
            0,
            0,
            0,
            0,
            0,
            "appreciatively"
         }),
       "wink":
         ({ "You try and wink at yourself but fail.",
            "tries to wink back at $pself but fails.",
            "You wink at $o.",
            "winks at you.",
            "winks at $o.",
            0,
            0,
            0
         }),
       "worship":
         ({ "You worship yourself.",
            "drops to $p knees and worships $pself.",
            "You fall you your knees in worship to $o.",
            "falls to $p knees in worship to you.",
            "falls to $p knees in worship of $o.",
            0,
            0,
            0
         }),
       "yawn":
         ({ "You yawn %s.",
            "yawns %s.",
            0,
            0,
            0,
            0,
            0,
            "tiredly"
         }),
   ]);
}
