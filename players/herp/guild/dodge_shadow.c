/* 930202 mud@mud.edvz.uni-linz.ac.at Herp aka Herbert Rosmanith */

/*----------------------------------------------------------------*
 * I know this really shouldn't be a guild ability.               *
 * It really should be coded into player, or, even better,        *
 * into living.c. We will do this when we recode living, player   *
 * and monster. Until then it is a thieves-skill.                 *
 *----------------------------------------------------------------*/

#define TP	this_player()
#define RM	"race/master"
#define Str	0
#define Dex	1
#define Con	2
#define Int	3
#define Wis	4
#define Chr	5
#define MAX_ST	30
#define W_DODGE	100		/* weight*100/strength max for dodge */

#if 0
#define SAY(x)	tell_object(owner,x)
#else
#define SAY(x)
#endif

object owner;			/* Whom we are shadowing */

start_shadow(object ob) {
  owner=ob;
  shadow(ob,1);
}

/* obj/player::hit_player is overwritten here */

hit_player(dam,kind) {
string n;
int i,d,c,g,h,m;
object ob;

SAY("hit_player: dam("+dam+") kind("+kind+")\n");
  d=owner->query_dex() - TP->query_dex();	/* delta dexterity */
  c=owner->query_chr() - TP->query_chr();	/* delta charisma */
  g=owner->query_weight();			/* what are we carrying ? */
  h=g*100/owner->query_str();
  n=owner->query_name();

  /* We only allow 0=normal, 2=dexterity damage */

ob=owner->query_armour();
SAY("hit_player: ^d "+d+" ^c "+c+"\n");
  if (kind!=0 && kind!=2 || d<0 || c<0 ||
      h > W_DODGE)
     return owner->hit_player(dam,kind);	/* original route */
SAY("hit_player: passed 1st check\n");
  if (!(m=RM->query_max_stat(owner->query_race(),Dex)))
	m=MAX_ST;

  /* First we check if a complete dodge of the attack is possible */

  if (d>0) {					/* positive delta-dex */
SAY("hit_player: d>0\n");
     i=d*(W_DODGE-h)/m;		/* dodge % possibilty reduced by weight */
SAY("hit_player: d, "+i+"%\n");
     if (random(100)<i) {	/* We dodge COMPLETELY ! */
	write(n+" dodges your attack to hit "+owner->query_objective()+".\n");
	say(n+" swiftly dodges the attack of "
				+TP->query_name()+".\n");
	tell_object(owner,"You swiftly dodge the attack of "+TP->query_name()+".\n");
        return 0;
     }
  }

  /* It isn't possible to dodge. But maybe we can reduce the damage ? */

  if (!(m=RM->query_max_stat(owner->query_race(),Chr)))
	m=MAX_ST;

  if (c>0) {
SAY("hit_player: c>0\n");
     i=c*(W_DODGE-h)/m;		/* damage % possibilty reduced by weight */
SAY("hit_player: c(1), "+i+"%\n");
     i=random(100-i)/2+50;	/* Minimum: 50 % damage */
SAY("hit_player: c, "+i+"%\n");
     dam=dam*i/100;
     i=owner->hit_player(dam,kind);
     write(owner->query_name()+" tried to dodge your attack, but got hit.\n");
     if (i) say(owner->query_name()+" tried to dodge the attack of "
	+TP->query_name()+", but got hit.\n");
     tell_object(owner,"You tried to dodge the attack of "+TP->query_name()
	+", but got hit.\n");
     return i;
  }

  /* Everything failed. We return the full damage */

  return owner->hit_player(dam,kind);

}
