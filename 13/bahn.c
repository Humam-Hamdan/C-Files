

enum Types {S, RB, Re};

enum {MAX_LENGTH = 40};
enum {MAX_NAME = 30};
enum {MAX_STAGE = 10};

typedef struct{
    char von[MAX_LENGTH];
    char nach[MAX_LENGTH];
    int nummer;
    int dauer;
    enum Types type;
} Stage;

typedef struct{
    char name[MAX_NAME];
    int num_stages;
    Stage all[MAX_STAGE];
} Ride;

void pureRide(const Ride* r){
    // Check if there is a NULL or a mismatch and print where is it.
}

// Wuppertal HBF to Koeln HFB, 45 min, RB 48.
// Nuernberg HBF to Muenchen HBF, 108 min, RE 1.
// Max Mustermann = 1 & 2.
// Check for missing rides -spoiler: there are-.

