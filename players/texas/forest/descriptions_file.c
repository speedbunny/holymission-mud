/*
* Created by Texas
* 28 March 1998
*
* This file is simply a list of descriptions which are returned
* as a string argument to set_long() or long_desc = (arg)
* There are better ways to do this, but this is nice and simple
* and as long as you don't have too many rooms using it
* then it will not become too inefficient.
*
* For larger numbers of rooms you should use other methods if you
* want to create a similar effect.
*
*/

string query_forest_desc()
{

    switch(random(17))
    {

	case 0:
	    return "\
You see only green tree trunks of innumerable sizes and shapes. Some \
stretch up as far as you can see, while others are merely gnarled or \
branched. All the trees are covered with green and grey moss and various \
slimy, shaggy growths. Your feet are surrounded by twisted and interlaced \
roots which appear to have the sole purpose of trying to trip you up.\n";

	case 1:
	    return "\
A tangle of shadows and murky darkness, screened away from the world \
outside by trees and scrub that are twisted and interwoven so that you \
can see neither the beginning nor end of it. The vegetation here has a \
grey cast about it that mutes its natural green, leaving the land \
looking sick and wintry.\n";

	case 2:
	    return "\
Mist hangs overhead, swirling thick across the treetops. Tree trunks \
thick with mold grow gnarled and bent, with limbs coiling out like \
spiders legs, choked with vines and brush. Dry wood and scrub litter \
the forest floor, decaying slowly in the dark ground, giving it an \
unpleasantly soft, spongy feel.\n";

	case 3:
	    return "\
You are in the deep gloom of the forest. Massive trees wrap themselves \
close about you until all but the faintest streamers of light are shut \
away, leaving only the narrow, rutted pathway on which you walk.\n";

	case 4:
	    return "\
The forest. Damp with must and rot, it has the look of something \
misshapen and grotesque. Its as if nature has stunted the land and the \
life within this forest, then bent down within itself so that it might \
never be made to breathe, eat and drink the stench that arose from its \
own death.\n";

	case 5:
	    return "\
Deep in the forest. Few have entered these parts and lived. The trees \
here grow tall, and the wood has a dark and menacing air about it, as \
though it is watching your every move. You fight hard to resist an urge \
to look over your shoulder.\n";

	case 6:
	    return "\
The air here is thick and stifling, with no sounds save the occasional \
drip of water falling through the still leaves. Not a single noise can \
be heard save the patter of your own feet as they shuffle through the \
undergrowth.\n";

	case 7:
	    return "\
The sun here shines in long streamers through cracks in the heavy \
branches. Beneath you fallen leaves and twigs are sodden with dew, \
making a cushion that masks the sound of your passage.\n";

	case 8:
	    return "\
The trees prevent you from seeinf much of anything, their great girth \
ranging from 3 to 10 feet in diameter, and their huge roots stretching \
out from the trunks like mammoth fingers, relentlessly digging their way \
into the forest floor.\n";

	case 9:
	    return "\
Thickly clustered trees, with rough disjointed trunks. Dead needles \
lie in heaps over the whole of the forest floor, creating a soft, \
silent matting to hide your passage.\n";

	case 10:
	    return "\
The white-bark trees rise tall and lean, touching near their skeletal \
tops like some intricate spiders web, leaving the sky above in a \
fascinatingly intricate design.\n";

	case 11:
	    return "\
The trees here are huge, bent, and hoary, warped somehow from the way \
that natures hand had shaped them. Within their midst are massive \
stalks of scrub and weed, grown to disproportionate size, and vines \
that wind and twist over anything like snakes with neither head nor \
tail.\n";

	case 12:
	    return "\
The colour of this section of forest is not the vibrant spring green \
that you would expect, but a dull geyish color that bears the cast of \
something dying with the freeze of winter.\n";

	case 13:
	    return "\
A seething mass of trunks, limbs, and vines shrouded in trailers of mist \
and the rise and fall of life that has rooted here, its breath hissing \
in steady cadence. Within this ravaged forest, nothing other than the \
forest itself gives any evidence of its existence.\n";

	case 14:
	    return "\
The trees here are enourmous, and many vast, gnarled oaks lift their \
bare arms among the dark firs and spruces. The forest floor is covered \
with a kind of grey moss that looks diseased and unwholesome.\n";

	case 15:
	    return "\
The woods here are very dark. The sense of watchfullness is all around \
you, that wary awareness you have felt since entering this wood, but now \
you feel something else too. The great trees stir uneasily, and a \
million tiny messages seem to pass amongst the rustling leaves.\n";

	case 16:
	    return "\
The forest roof seems to close about you, shutting away the sunlight, \
leaving you wrapped in the shadows, heat and unbearable stench of this \
rotting forest.\n";

	default:
	    return "\
A deep, dark, gloomy forest. Faint sounds skitter and lurch in the \
stillness, while shadows slip like wraiths through the neverending \
gloom. The trees ahere are heavy with spiny leaves that shimmer in \
streaks of incandescant silver.\n"; 

    }
}
