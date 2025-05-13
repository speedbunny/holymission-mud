string get_pretitle(int lvl,int gender) {
    mixed ret;

    switch(lvl) {
    case 1..22:
	ret="";
	break;
    case 23..52:
	ret="Vagabond";
	break;
    case 53..62:
	ret="Vagabond Scholar";
	break;
    case 63..72:
	ret="Vagabond Explorer";
	break;
    case 73..82:
	ret="Vagabond Specialist";
	break;
    case 83..92:
	ret="Vagabond Caretaker";
	break;
    case 93..99:
	ret="Not yet determined";
	break;
    default:
	ret="";
	break;
    }
    if(!pointerp(ret))
	return ret;
    else
	return ret[gender];
}



string get_title(int lvl,int gender) {
    mixed ret;

    switch(lvl) {
    case 1:
	ret=({
	  "Freshmen of the Vagabonds",
	  "Freshwoman of the Vagabonds",
	});
	break;
    case 2:
	ret="Student of Existence";
	break;
    case 3:
	ret="Student of Extent";
	break;
    case 4:
	ret="Student of Space";
	break;
    case 5:
	ret="Student of Physical Law";
	break;
    case 6:
	ret="Student of the Past";
	break;
    case 7:
	ret="Student of the Future";
	break;
    case 8:
	ret="Student of Time";
	break;
    case 9:
	ret="Student of the Art of Tesseract";
	break;
    case 10:
	ret="Student of Quantum Realities";
	break;
    case 11:
	ret="Student of Alternate Realities";
	break;
    case 12:
	ret="Ascendant Member of the Vagabond Guild";
	break;
    case 13:
	ret="Learner of Existence";
	break;
    case 14:
	ret="Learner of Extent";
	break;
    case 15:
	ret="Learner of Space";
	break;
    case 16:
	ret="Learner of Physical Law";
	break;
    case 17:
	ret="Learner of the Past";
	break;
    case 18:
	ret="Learner of the Future";
	break;
    case 19:
	ret="Learner of Time";
	break;
    case 20:
	ret="Learner of the Art of Tesseract";
	break;
    case 21:
	ret="Learner of Quantum Realities";
	break;
    case 22:
	ret="Learner of Alternate Realities";
	break;
    case 23:
	ret="Watcher of Existence";
	break;
    case 24:
	ret="Watcher of Extent";
	break;
    case 25:
	ret="Watcher of Space";
	break;
    case 26:
	ret="Watcher of Physical Law";
	break;
    case 27:
	ret="Watcher of the Past";
	break;
    case 28:
	ret="Watcher of the Future";
	break;
    case 29:
	ret="Watcher of Time";
	break;
    case 30:
	ret="Watcher of the Art of Tesseract";
	break;
    case 31:
	ret="Watcher of Quantum Realities";
	break;
    case 32:
	ret="Watcher of Alternate Realities";
	break;
    case 33:
	ret="Traveller of Existence";
	break;
    case 34:
	ret="Traveller of Extent";
	break;
    case 35:
	ret="Traveller of Space";
	break;
    case 36:
	ret="Traveller of Physical Law";
	break;
    case 37:
	ret="Traveller of the Past";
	break;
    case 38:
	ret="Traveller of the Future";
	break;
    case 39:
	ret="Traveller of Time";
	break;
    case 40:
	ret="Traveller of the Art of Tesseract";
	break;
    case 41:
	ret="Traveller of Quantum Realities";
	break;
    case 42:
	ret="Traveller of Alternate Realities";
	break;
    case 43:
	ret="Executor of Existence";
	break;
    case 44:
	ret="Executor of Extent";
	break;
    case 45:
	ret="Executor of Space";
	break;
    case 46:
	ret="Executor of Physical Law";
	break;
    case 47:
	ret="Executor of the Past";
	break;
    case 48:
	ret="Executor of the Future";
	break;
    case 49:
	ret="Executor of Time";
	break;
    case 50:
	ret="Executor of the Art of Tesseract";
	break;
    case 51:
	ret="Executor of Quantum Realities";
	break;
    case 52:
	ret="Executor of Alternate Realities";
	break;
    case 53:
	ret="Recorder of Existence";
	break;
    case 54:
	ret="Recorder of Extent";
	break;
    case 55:
	ret="Recorder of Space";
	break;
    case 56:
	ret="Recorder of Physical Law";
	break;
    case 57:
	ret="Recorder of the Past";
	break;
    case 58:
	ret="Recorder of the Future";
	break;
    case 59:
	ret="Recorder of Time";
	break;
    case 60:
	ret="Recorder of the Art of Tesseract";
	break;
    case 61:
	ret="Recorder of Quantum Realities";
	break;
    case 62:
	ret="Recorder of Alternate Realities";
	break;
    case 63:
	ret="Guide to Existence";
	break;
    case 64:
	ret="Guide to Extent";
	break;
    case 65:
	ret="Guide to Space";
	break;
    case 66:
	ret="Guide to Physical Law";
	break;
    case 67:
	ret="Guide to the Past";
	break;
    case 68:
	ret="Guide to the Future";
	break;
    case 69:
	ret="Guide to Time";
	break;
    case 70:
	ret="Guide to the Art of Tesseract";
	break;
    case 71:
	ret="Guide to Quantum Realities";
	break;
    case 72:
	ret="Guide to Alternate Realities";
	break;
    case 73:
	ret="Authority on Existence";
	break;
    case 74:
	ret="Authority on Extent";
	break;
    case 75:
	ret="Authority on Space";
	break;
    case 76:
	ret="Authority on Physical Law";
	break;
    case 77:
	ret="Authority on the Past";
	break;
    case 78:
	ret="Authority on the Future";
	break;
    case 79:
	ret="Authority on Time";
	break;
    case 80:
	ret="Authority on the Art of Tesseract";
	break;
    case 81:
	ret="Authority on Quantum Realities";
	break;
    case 82:
	ret="Authority on Alternate Realities";
	break;
    case 83:
	ret="Regulator of Existence";
	break;
    case 84:
	ret="Regulator of Extent";
	break;
    case 85:
	ret="Regulator of Space";
	break;
    case 86:
	ret="Regulator of Physical Law";
	break;
    case 87:
	ret="Regulator of the Past";
	break;
    case 88:
	ret="Regulator of the Future";
	break;
    case 89:
	ret="Regulator of Time";
	break;
    case 90:
	ret="Regulator of the Art of Tesseract";
	break;
    case 91:
	ret="Regulator of Quantum Realities";
	break;
    case 92:
	ret="Regulator of Alternate Realities";
	break;
    case 93..99:
	ret="Not yet determined";
	break;
    default:
	ret="Apprentice Wizard";
	break;
    }
    if(!pointerp(ret))
	return ret;
    else
	return ret[gender];
}
