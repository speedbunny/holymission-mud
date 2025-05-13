#include "/players/nylakoorub/guild/defines.h"
#include "/sys/levels.h"



level (ob) {
    string lvl;
    lvl = ob->query_level();
    switch(lvl) {
    case 0..99 :
	return ladjust(lvl,maxlevelchr);
    case L_APPR :
	return ladjust("Apprentice",maxlevelchr);
    case L_NEWWIZ :
	return ladjust("New-Wiz",maxlevelchr);
    case L_WIZ :
	return ladjust("Wizard",maxlevelchr);
    case L_RETD :
	return ladjust("Retired",maxlevelchr);
    case L_SAGE :
	return ladjust("Senior",maxlevelchr);
    case L_ELDER :
	return ladjust("Elder",maxlevelchr);
    case L_ARCH :
	return ladjust("Arch",maxlevelchr);
    case L_SPEC :
	return ladjust("Spec.",maxlevelchr);
    case L_GOD :
	return ladjust("God",maxlevelchr);
    default :
	return ladjust(" ? ",maxlevelchr);
    }
}

