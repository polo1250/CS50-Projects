#include <stdio.h>
#include <cs50.h>
#include <crypt.h>
#include <string.h>

string words_dict[] = {"THE", "CALL", "LOL", "EAT", "AAA", "able", "acid", "act", "ad", "add", "age", "ago", "ah", "aid", "aide", "AIDS", "aim", "air", "all", "ally", "also", "AM", "and", "any", "Arab", "area", "arm", "army", "art", "as", "ask", "at", "auto", "away", "baby", "back", "bad", "bag", "bake", "ball", "ban", "band", "bank", "bar", "base", "be", "bean", "bear", "beat", "bed", "beer", "bell", "belt", "bend", "best", "bet", "big", "bike", "bill", "bind", "bird", "bit", "bite", "blow", "blue", "boat", "body", "bomb", "bond", "bone", "book", "boom", "boot", "born", "boss", "both", "bowl", "box", "boy", "buck", "burn", "bury", "bus", "busy", "but", "buy", "by", "cake", "call", "camp", "can", "cap", "car", "card", "care", "case", "cash", "cast", "cat", "cell", "CEO", "chef", "chip", "cite", "city", "club", "clue", "coal", "coat", "code", "cold", "come", "cook", "cool", "cop", "cope", "copy", "core", "corn", "cost", "cow", "crack", "crew", "crop", "cry", "cs50", "cup", "cut", "dad", "dare", "dark", "data", "date", "day", "dead", "deal", "dear", "debt", "deck", "deep", "deer", "deny", "desk", "die", "diet", "dig", "dirt", "dish", "DNA", "do", "dog", "door", "down", "drag", "draw", "drop", "drug", "dry", "due", "dust", "duty", "each", "ear", "earn", "ease", "east", "easy", "eat", "edge", "egg", "else", "end", "era", "etc", "even", "ever", "eye", "face", "fact", "fade", "fail", "fair", "fall", "fan", "far", "farm", "fast", "fat", "fate", "fear", "fee", "feed", "feel", "few", "file", "fill", "film", "find", "fine", "fire", "firm", "fish", "fit", "five", "fix", "flag", "flat", "flee", "flow", "fly", "folk", "food", "foot", "for", "form", "four", "free", "from", "fuel", "full", "fun", "fund", "gain", "game", "gang", "gap", "gas", "gate", "gay", "gaze", "gear", "gene", "get", "gift", "girl", "give", "glad", "go", "goal", "God", "gold", "golf", "good", "grab", "gray", "grow", "gun", "guy", "hair", "half", "hall", "hand", "hang", "hard", "harvard", "hat", "hate", "have", "he", "head", "hear", "heat", "heel", "hell", "help", "her", "here", "hero", "hey", "hi", "hide", "high", "hill", "him", "hip", "hire", "his", "hit", "hold", "hole", "holy", "home", "hope", "host", "hot", "hour", "how", "huge", "hurt", "I", "ice", "idea", "ie", "if", "ill", "in", "into", "iron", "it", "item", "its", "jail", "jet", "Jew", "job", "join", "joke", "joy", "jump", "jury", "just", "keep", "key", "kick", "kid", "kill", "kind", "king", "kiss", "knee", "know", "lab", "lack", "lady", "lake", "land", "lap", "last", "late", "law", "lawn", "lay", "lead", "leaf", "lean", "left", "leg", "less", "let", "lie", "life", "lift", "like", "line", "link", "lip", "list", "live", "load", "loan", "lock", "long", "look", "lol", "lose", "loss", "lost", "lot", "lots", "loud", "love", "low", "luck", "lung", "mad", "mail", "main", "make", "male", "mall", "man", "many", "map", "mark", "mask", "mass", "math", "may", "me", "meal", "mean", "meat", "meet", "menu", "mere", "mess", "milk", "mind", "mine", "miss", "mix", "mode", "mom", "mood", "moon", "more", "most", "move", "Mr", "Mrs", "Ms", "much", "must", "my", "myth", "name", "near", "neck", "need", "net", "new", "news", "next", "nice", "nine", "no", "nod", "none", "nor", "nose", "not", "note", "now", "n\'t", "nut", "odd", "odds", "of", "off", "oh", "oil", "ok", "okay", "old", "on", "once", "one", "only", "onto", "open", "or", "our", "out", "oven", "over", "owe", "own", "pace", "pack", "page", "pain", "pair", "pale", "palm", "pan", "pant", "park", "part", "pass", "past", "path", "pay", "PC", "peak", "peer", "per", "pet", "pick", "pie", "pile", "pine", "pink", "pipe", "plan", "play", "plot", "plus", "PM", "poem", "poet", "pole", "poll", "pool", "poor", "pop", "port", "pose", "post", "pot", "pour", "pray", "pull", "pure", "push", "put", "quit", "race", "rail", "rain", "rank", "rare", "rate", "raw", "read", "real", "red", "rely", "rest", "rice", "rich", "rid", "ride", "ring", "rise", "risk", "road", "rock", "role", "roll", "roof", "room", "root", "rope", "rose", "row", "rub", "rule", "run", "rush", "sad", "safe", "sake", "sale", "salt", "same", "sand", "save", "say", "sea", "seat", "see", "seed", "seek", "seem", "self", "sell", "send", "set", "sex", "she", "ship", "shit", "shoe", "shop", "shot", "show", "shut", "sick", "side", "sigh", "sign", "sin", "sing", "sink", "sir", "sit", "site", "six", "size", "ski", "skin", "sky", "slip", "slow", "snap", "snow", "so", "soft", "soil", "some", "son", "song", "soon", "sort", "soul", "soup", "spin", "spot", "star", "stay", "step", "stir", "stop", "such", "sue", "suit", "sun", "sure", "swim", "tail", "take", "tale", "talk", "tall", "tank", "tap", "tape", "task", "tax", "tea", "team", "tear", "teen", "tell", "ten", "tend", "tent", "term", "test", "text", "than", "that", "the", "them", "then", "they", "thin", "this", "thus", "tie", "time", "tiny", "tip", "tire", "to", "toe", "tone", "too", "tool", "top", "toss", "tour", "town", "toy", "tree", "trip", "true", "try", "tube", "turn", "TV", "twin", "two", "type", "ugly", "unit", "up", "upon", "urge", "us", "use", "used", "user", "vary", "vast", "very", "via", "view", "vote", "vs", "wage", "wait", "wake", "walk", "wall", "want", "war", "warm", "warn", "wash", "wave", "way", "we", "weak", "wear", "week", "well", "west", "wet", "what", "when", "who", "whom", "why", "wide", "wife", "wild", "will", "win", "wind", "wine", "wing", "wipe", "wire", "wise", "wish", "with", "wood", "word", "work", "wrap", "yard", "yeah", "year", "yell", "yes", "yet", "you", "your", "zone", "", "a", "able", "act", "add", "age", "ago", "air", "all", "also", "and", "any", "area", "arm", "art", "as", "ask", "at", "away", "baby", "back", "bad", "bag", "ball", "bank", "bar", "base", "be", "beat", "bed", "best", "big", "bill", "bit", "blue", "body", "book", "born", "both", "box", "boy", "but", "buy", "by", "call", "can", "car", "card", "care", "case", "cell", "city", "cold", "come", "cost", "cup", "cut", "dark", "data", "day", "dead", "deal", "deep", "die", "do", "dog", "door", "down", "draw", "drop", "drug", "each", "east", "easy", "eat", "edge", "else", "end", "even", "ever", "eye", "face", "fact", "fail", "fall", "far", "fast", "fear", "feel", "few", "fill", "film", "find", "fine", "fire", "firm", "fish", "five", "fly", "food", "foot", "for", "form", "four", "free", "from", "full", "fund", "game", "gas", "get", "girl", "give", "go", "goal", "good", "grow", "gun", "guy", "hair", "half", "hand", "hang", "hard", "have", "he", "head", "hear", "heat", "help", "her", "here", "high", "him", "his", "hit", "hold", "home", "hope", "hot", "hour", "how", "huge", "I", "idea", "if", "in", "into", "it", "item", "its", "job", "join", "just", "keep", "key", "kid", "kill", "kind", "know", "land", "last", "late", "law", "lay", "lead", "left", "leg", "less", "let", "lie", "life", "like", "line", "list", "live", "long", "look", "lose", "loss", "lot", "love", "low", "main", "make", "man", "many", "may", "me", "mean", "meet", "mind", "miss", "more", "most", "move", "Mr", "Mrs", "much", "must", "my", "name", "near", "need", "new", "news", "next", "nice", "no", "none", "nor", "not", "note", "now", "n\'t", "of", "off", "oh", "oil", "ok", "old", "on", "once", "one", "only", "onto", "open", "or", "our", "out", "over", "own", "page", "pain", "part", "pass", "past", "pay", "per", "pick", "plan", "play", "PM", "poor", "pull", "push", "put", "race", "rate", "read", "real", "red", "rest", "rich", "rise", "risk", "road", "rock", "role", "room", "rule", "run", "safe", "same", "save", "say", "sea", "seat", "see", "seek", "seem", "sell", "send", "set", "sex", "she", "shot", "show", "side", "sign", "sing", "sit", "site", "six", "size", "skin", "so", "some", "son", "song", "soon", "sort", "star", "stay", "step", "stop", "such", "sure", "take", "talk", "task", "tax", "team", "tell", "ten", "tend", "term", "test", "than", "that", "the", "them", "then", "they", "this", "thus", "time", "to", "too", "top", "town", "tree", "trip", "true", "try", "turn", "TV", "two", "type", "unit", "up", "upon", "us", "use", "very", "view", "vote", "wait", "walk", "wall", "want", "war", "way", "we", "wear", "week", "well", "west", "what", "when", "who", "whom", "why", "wide", "wife", "will", "win", "wind", "wish", "with", "word", "work", "yard", "yeah", "year", "yes", "yet", "you", "your", "A", "ABLE", "ACID", "ACT", "AD", "ADD", "AGE", "AGO", "AH", "AID", "AIDE", "AIDS", "AIM", "AIR", "ALL", "ALLY", "ALSO", "AM", "AND", "ANY", "ARAB", "AREA", "ARM", "ARMY", "ART", "AS", "ASK", "AT", "AUTO", "AWAY", "BABY", "BACK", "BAD", "BAG", "BAKE", "BALL", "BAN", "BAND", "BANK", "BAR", "BASE", "BE", "BEAN", "BEAR", "BEAT", "BED", "BEER", "BELL", "BELT", "BEND", "BEST", "BET", "BIG", "BIKE", "BILL", "BIND", "BIRD", "BIT", "BITE", "BLOW", "BLUE", "BOAT", "BODY", "BOMB", "BOND", "BONE", "BOOK", "BOOM", "BOOT", "BORN", "BOSS", "BOTH", "BOWL", "BOX", "BOY", "BUCK", "BURN", "BURY", "BUS", "BUSY", "BUT", "BUY", "BY", "CAKE", "CALL", "CAMP", "CAN", "CAP", "CAR", "CARD", "CARE", "CASE", "CASH", "CAST", "CAT", "CELL", "CEO", "CHEF", "CHIP", "CITE", "CITY", "CLUB", "CLUE", "COAL", "COAT", "CODE", "COLD", "COME", "COOK", "COOL", "COP", "COPE", "COPY", "CORE", "CORN", "COST", "COW", "CRACK", "CREW", "CROP", "CRY", "CS50", "CUP", "CUT", "DAD", "DARE", "DARK", "DATA", "DATE", "DAY", "DEAD", "DEAL", "DEAR", "DEBT", "DECK", "DEEP", "DEER", "DENY", "DESK", "DIE", "DIET", "DIG", "DIRT", "DISH", "DNA", "DO", "DOG", "DOOR", "DOWN", "DRAG", "DRAW", "DROP", "DRUG", "DRY", "DUE", "DUST", "DUTY", "EACH", "EAR", "EARN", "EASE", "EAST", "EASY", "EAT", "EDGE", "EGG", "ELSE", "END", "ERA", "ETC", "EVEN", "EVER", "EYE", "FACE", "FACT", "FADE", "FAIL", "FAIR", "FALL", "FAN", "FAR", "FARM", "FAST", "FAT", "FATE", "FEAR", "FEE", "FEED", "FEEL", "FEW", "FILE", "FILL", "FILM", "FIND", "FINE", "FIRE", "FIRM", "FISH", "FIT", "FIVE", "FIX", "FLAG", "FLAT", "FLEE", "FLOW", "FLY", "FOLK", "FOOD", "FOOT", "FOR", "FORM", "FOUR", "FREE", "FROM", "FUEL", "FULL", "FUN", "FUND", "GAIN", "GAME", "GANG", "GAP", "GAS", "GATE", "GAY", "GAZE", "GEAR", "GENE", "GET", "GIFT", "GIRL", "GIVE", "GLAD", "GO", "GOAL", "GOD", "GOLD", "GOLF", "GOOD", "GRAB", "GRAY", "GROW", "GUN", "GUY", "HAIR", "HALF", "HALL", "HAND", "HANG", "HARD", "HARVARD", "HAT", "HATE", "HAVE", "HE", "HEAD", "HEAR", "HEAT", "HEEL", "HELL", "HELP", "HER", "HERE", "HERO", "HEY", "HI", "HIDE", "HIGH", "HILL", "HIM", "HIP", "HIRE", "HIS", "HIT", "HOLD", "HOLE", "HOLY", "HOME", "HOPE", "HOST", "HOT", "HOUR", "HOW", "HUGE", "HURT", "I", "ICE", "IDEA", "IE", "IF", "ILL", "IN", "INTO", "IRON", "IT", "ITEM", "ITS", "JAIL", "JET", "JEW", "JOB", "JOIN", "JOKE", "JOY", "JUMP", "JURY", "JUST", "KEEP", "KEY", "KICK", "KID", "KILL", "KIND", "KING", "KISS", "KNEE", "KNOW", "LAB", "LACK", "LADY", "LAKE", "LAND", "LAP", "LAST", "LATE", "LAW", "LAWN", "LAY", "LEAD", "LEAF", "LEAN", "LEFT", "LEG", "LESS", "LET", "LIE", "LIFE", "LIFT", "LIKE", "LINE", "LINK", "LIP", "LIST", "LIVE", "LOAD", "LOAN", "LOCK", "LOL", "LONG", "LOOK", "LOSE", "LOSS", "LOST", "LOT", "LOTS", "LOUD", "LOVE", "LOW", "LUCK", "LUNG", "MAD", "MAIL", "MAIN", "MAKE", "MALE", "MALL", "MAN", "MANY", "MAP", "MARK", "MASK", "MASS", "MATH", "MAY", "ME", "MEAL", "MEAN", "MEAT", "MEET", "MENU", "MERE", "MESS", "MILK", "MIND", "MINE", "MISS", "MIX", "MODE", "MOM", "MOOD", "MOON", "MORE", "MOST", "MOVE", "MR", "MRS", "MS", "MUCH", "MUST", "MY", "MYTH", "NAME", "NEAR", "NECK", "NEED", "NET", "NEW", "NEWS", "NEXT", "NICE", "NINE", "NO", "NOD", "NONE", "NOR", "NOSE", "NOT", "NOTE", "NOW", "N\'T", "NUT", "ODD", "ODDS", "OF", "OFF", "OH", "OIL", "OK", "OKAY", "OLD", "ON", "ONCE", "ONE", "ONLY", "ONTO", "OPEN", "OR", "OUR", "OUT", "OVEN", "OVER", "OWE", "OWN", "PACE", "PACK", "PAGE", "PAIN", "PAIR", "PALE", "PALM", "PAN", "PANT", "PARK", "PART", "PASS", "PAST", "PATH", "PAY", "PC", "PEAK", "PEER", "PER", "PET", "PICK", "PIE", "PILE", "PINE", "PINK", "PIPE", "PLAN", "PLAY", "PLOT", "PLUS", "PM", "POEM", "POET", "POLE", "POLL", "POOL", "POOR", "POP", "PORT", "POSE", "POST", "POT", "POUR", "PRAY", "PULL", "PURE", "PUSH", "PUT", "QUIT", "RACE", "RAIL", "RAIN", "RANK", "RARE", "RATE", "RAW", "READ", "REAL", "RED", "RELY", "REST", "RICE", "RICH", "RID", "RIDE", "RING", "RISE", "RISK", "ROAD", "ROCK", "ROLE", "ROLL", "ROOF", "ROOM", "ROOT", "ROPE", "ROSE", "ROW", "RUB", "RULE", "RUN", "RUSH", "SAD", "SAFE", "SAKE", "SALE", "SALT", "SAME", "SAND", "SAVE", "SAY", "SEA", "SEAT", "SEE", "SEED", "SEEK", "SEEM", "SELF", "SELL", "SEND", "SET", "SEX", "SHE", "SHIP", "SHIT", "SHOE", "SHOP", "SHOT", "SHOW", "SHUT", "SICK", "SIDE", "SIGH", "SIGN", "SIN", "SING", "SINK", "SIR", "SIT", "SITE", "SIX", "SIZE", "SKI", "SKIN", "SKY", "SLIP", "SLOW", "SNAP", "SNOW", "SO", "SOFT", "SOIL", "SOME", "SON", "SONG", "SOON", "SORT", "SOUL", "SOUP", "SPIN", "SPOT", "STAR", "STAY", "STEP", "STIR", "STOP", "SUCH", "SUE", "SUIT", "SUN", "SURE", "SWIM", "TAIL", "TAKE", "TALE", "TALK", "TALL", "TANK", "TAP", "TAPE", "TASK", "TAX", "TEA", "TEAM", "TEAR", "TEEN", "TELL", "TEN", "TEND", "TENT", "TERM", "TEST", "TEXT", "THAN", "THAT", "THE", "THEM", "THEN", "THEY", "THIN", "THIS", "THUS", "TIE", "TIME", "TINY", "TIP", "TIRE", "TO", "TOE", "TONE", "TOO", "TOOL", "TOP", "TOSS", "TOUR", "TOWN", "TOY", "TREE", "TRIP", "TRUE", "TRY", "TUBE", "TURN", "TV", "TWIN", "TWO", "TYPE", "UGLY", "UNIT", "UP", "UPON", "URGE", "US", "USE", "USED", "USER", "VARY", "VAST", "VERY", "VIA", "VIEW", "VOTE", "VS", "WAGE", "WAIT", "WAKE", "WALK", "WALL", "WANT", "WAR", "WARM", "WARN", "WASH", "WAVE", "WAY", "WE", "WEAK", "WEAR", "WEEK", "WELL", "WEST", "WET", "WHAT", "WHEN", "WHO", "WHOM", "WHY", "WIDE", "WIFE", "WILD", "WILL", "WIN", "WIND", "WINE", "WING", "WIPE", "WIRE", "WISE", "WISH", "WITH", "WOOD", "WORD", "WORK", "WRAP", "YARD", "YEAH", "YEAR", "YELL", "YES", "YET", "YOU", "YOUR", "ZONE", "", "A", "ABLE", "ACT", "ADD", "AGE", "AGO", "AIR", "ALL", "ALSO", "AND", "ANY", "AREA", "ARM", "ART", "AS", "ASK", "AT", "AWAY", "BABY", "BACK", "BAD", "BAG", "BALL", "BANK", "BAR", "BASE", "BE", "BEAT", "BED", "BEST", "BIG", "BILL", "BIT", "BLUE", "BODY", "BOOK", "BORN", "BOTH", "BOX", "BOY", "BUT", "BUY", "BY", "CALL", "CAN", "CAR", "CARD", "CARE", "CASE", "CELL", "CITY", "COLD", "COME", "COST", "CUP", "CUT", "DARK", "DATA", "DAY", "DEAD", "DEAL", "DEEP", "DIE", "DO", "DOG", "DOOR", "DOWN", "DRAW", "DROP", "DRUG", "EACH", "EAST", "EASY", "EAT", "EDGE", "ELSE", "END", "EVEN", "EVER", "EYE", "FACE", "FACT", "FAIL", "FALL", "FAR", "FAST", "FEAR", "FEEL", "FEW", "FILL", "FILM", "FIND", "FINE", "FIRE", "FIRM", "FISH", "FIVE", "FLY", "FOOD", "FOOT", "FOR", "FORM", "FOUR", "FREE", "FROM", "FULL", "FUND", "GAME", "GAS", "GET", "GIRL", "GIVE", "GO", "GOAL", "GOOD", "GROW", "GUN", "GUY", "HAIR", "HALF", "HAND", "HANG", "HARD", "HAVE", "HE", "HEAD", "HEAR", "HEAT", "HELP", "HER", "HERE", "HIGH", "HIM", "HIS", "HIT", "HOLD", "HOME", "HOPE", "HOT", "HOUR", "HOW", "HUGE", "I", "IDEA", "IF", "IN", "INTO", "IT", "ITEM", "ITS", "JOB", "JOIN", "JUST", "KEEP", "KEY", "KID", "KILL", "KIND", "KNOW", "LAND", "LAST", "LATE", "LAW", "LAY", "LEAD", "LEFT", "LEG", "LESS", "LET", "LIE", "LIFE", "LIKE", "LINE", "LIST", "LIVE", "LONG", "LOOK", "LOSE", "LOSS", "LOT", "LOVE", "LOW", "MAIN", "MAKE", "MAN", "MANY", "MAY", "ME", "MEAN", "MEET", "MIND", "MISS", "MORE", "MOST", "MOVE", "MR", "MRS", "MUCH", "MUST", "MY", "NAME", "NEAR", "NEED", "NEW", "NEWS", "NEXT", "NICE", "NO", "NONE", "NOR", "NOT", "NOTE", "NOW", "N\'T", "OF", "OFF", "OH", "OIL", "OK", "OLD", "ON", "ONCE", "ONE", "ONLY", "ONTO", "OPEN", "OR", "OUR", "OUT", "OVER", "OWN", "PAGE", "PAIN", "PART", "PASS", "PAST", "PAY", "PER", "PICK", "PLAN", "PLAY", "PM", "POOR", "PULL", "PUSH", "PUT", "RACE", "RATE", "READ", "REAL", "RED", "REST", "RICH", "RISE", "RISK", "ROAD", "ROCK", "ROLE", "ROOM", "RULE", "RUN", "SAFE", "SAME", "SAVE", "SAY", "SEA", "SEAT", "SEE", "SEEK", "SEEM", "SELL", "SEND", "SET", "SEX", "SHE", "SHOT", "SHOW", "SIDE", "SIGN", "SING", "SIT", "SITE", "SIX", "SIZE", "SKIN", "SO", "SOME", "SON", "SONG", "SOON", "SORT", "STAR", "STAY", "STEP", "STOP", "SUCH", "SURE", "TAKE", "TALK", "TASK", "TAX", "TEAM", "TELL", "TEN", "TEND", "TERM", "TEST", "THAN", "THAT", "THE", "THEM", "THEN", "THEY", "THIS", "THUS", "TIME", "TO", "TOO", "TOP", "TOWN", "TREE", "TRIP", "TRUE", "TRY", "TURN", "TV", "TWO", "TYPE", "UNIT", "UP", "UPON", "US", "USE", "VERY", "VIEW", "VOTE", "WAIT", "WALK", "WALL", "WANT", "WAR", "WAY", "WE", "WEAR", "WEEK", "WELL", "WEST", "WHAT", "WHEN", "WHO", "WHOM", "WHY", "WIDE", "WIFE", "WILL", "WIN", "WIND", "WISH", "WITH", "WORD", "WORK", "YARD", "YEAH", "YEAR", "YES", "YET", "YOU", "YOUR"};

string alpha = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";

const int SALT_SIZE = 2;
const int DICT_SIZE = 2174;

//Important functions prototypes
void get_salt(char salt[], string hash);
bool found(string word, string hash, char salt[]);
string resolve_with_words(char salt[], string hash);
string generate_and_test(char salt[], string hash);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
    }
    else
    {
        char salt[SALT_SIZE];
        get_salt(salt, argv[1]);
        string result1 = resolve_with_words(salt, argv[1]);
        if (strcmp(result1, "##") == 0)
        {
            string result2 = generate_and_test(salt, argv[1]);
            if (strcmp(result2, "##") == 0)
            {
                printf("\n");
            }
            else
            {
                printf("%s\n", result2);
            }
        }
        else
        {
            printf("%s\n", result1);
        }
    }
    return 0;
}

//Retrieve the salt in the hash and put it in the salt variable
void get_salt(char salt[], string hash)
{
    for (int i = 0; i < SALT_SIZE; i++)
    {
        salt[i] = hash[i];
    }
}

//Hash the received word and compare it to the provided hash, return True if found, False //otherwise
bool found(string word, string hash, char salt[])
{
    string wordhash = crypt(word, salt);
    if (strcmp(hash, wordhash) != 0)
    {
        return false;
    }
    return true;
}

//Use the dictionary to find and return the password, otherwise return "##"
string resolve_with_words(char salt[], string hash)
{
    for (int i = 0; i < DICT_SIZE; i++)
    {
        bool answer = found(words_dict[i], hash, salt);
        if (answer)
        {
            return words_dict[i];
        }
    }
    return "##";
}

//Generate all alphabetical words and test them
string generate_and_test(char salt[], string hash)
{
    int n = strlen(alpha);
    string test1 = malloc(1 * sizeof(string));
    // test words with length 1
    for (int i = 0; i < n; i++)
    {
        strncpy(test1, &alpha[i], 1);
        bool answer = found(test1, hash, salt);
        if (answer)
        {
            return test1;
        }
    }

    free(test1);

    // test words with length 2
    string test2 = malloc(2 * sizeof(string));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char test[2] = "";
            test[0] = alpha[i];
            test[1] = alpha[j];
            strncpy(test2, test, 2);
            bool answer = found(test2, hash, salt);
            if (answer)
            {
                return test2;
            }
        }
    }

    free(test2);

    // test words with length 3
    string test3 = malloc(3 * sizeof(string));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                char test[3] = "";
                test[0] = alpha[i];
                test[1] = alpha[j];
                test[2] = alpha[k];
                strncpy(test3, test, 3);
                bool answer = found(test3, hash, salt);
                if (answer)
                {
                    return test3;
                }
            }
        }
    }

    free(test3);

    // test words with length 4
    string test4 = malloc(4 * sizeof(string));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    char test[4] = "";
                    test[0] = alpha[i];
                    test[1] = alpha[j];
                    test[2] = alpha[k];
                    test[3] = alpha[l];
                    strncpy(test4, test, 4);
                    bool answer = found(test4, hash, salt);
                    if (answer)
                    {
                        return test4;
                    }
                }
            }
        }
    }

    free(test4);

    // test words with length 5
    string test5 = malloc(4 * sizeof(string));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    for (int m = 0; m < n; m++)
                    {
                        char test[5] = "";
                        test[0] = alpha[i];
                        test[1] = alpha[j];
                        test[2] = alpha[k];
                        test[3] = alpha[l];
                        test[4] = alpha[m];
                        strncpy(test5, test, 5);
                        bool answer = found(test5, hash, salt);
                        if (answer)
                        {
                            return test5;
                        }
                    }
                }
            }
        }
    }
    free(test5);

    return "##";
}
