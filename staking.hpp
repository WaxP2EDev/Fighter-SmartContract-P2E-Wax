#include <eosio/eosio.hpp>
#include <eosio/system.hpp>
#include <eosio/asset.hpp>
#include <map>
#include <string>
#include <iterator>
#include <vector>
#include <math.h>
using namespace eosio;
using namespace std;

using std::string;
using std::vector;


typedef uint64_t id_type;

CONTRACT fighterReward : public eosio::contract {
  public:
    using contract::contract;
    blockbunnies(eosio::name receiver, eosio::name code, eosio::datastream<const char *> ds) : 
      contract(receiver, code, ds){} //thre precision of the symbol is the decimal precision of

 

    ACTION reward( name from, name to, id_type assets_id, string	memo ); 
    
  private:

    TABLE staker{
        name username; //name of the staking user
        asset fund_staked; // funds to be staked
        string place;
        vector<imeta> nftid_staked ;
        vector<imeta> toolnftid_staked;
        time_point_sec last_updated;
        time_point_sec next_run;
        asset collect_amount;
        bool isstaked; //if the users has already staked funds or not
        uint64_t primary_key() const {return username.value;}
    };
    typedef eosio::multi_index<name("stakerlist"), staker> stakers;
    stakers _staker_list;

    


};