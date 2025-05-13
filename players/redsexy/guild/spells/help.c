help(arg) {
  switch(arg) {
    case "guild":       case "levels":
    case "summon":      case "create":
    case "call":        case "brooch":
    case "drawhp":      case "drawsp":
    case "storehp":     case "storesp":
    case "hood":        case "inspect":
    case "state":       case "silence":
      
    case "raven":       case "wisp":
    case "beast":       case "roc":
    case "seeker":      case "golem":
      
    case "wolf":        case "triton":
    case "djinn":       case "vilstrak":
    case "efreet":      case "water":
    case "wind":        case "earth":
    case "fire":        case "power":
    case "lesser":      case "greater":
    case "lord":        case "arch":
      
    case "ice":         case "mud":
    case "cyclone":     case "smoke":
    case "blaze":       case "magma":
    case "bolt":
      break;

    default: return;
    }
  if(arg == "levels" || arg == "level") {
    GM->list_levels(GD);
    return 1;
  }
  cat("/" + HELP + arg);
  return 1;
}
