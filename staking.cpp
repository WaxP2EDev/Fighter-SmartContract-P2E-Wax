#include <staking.hpp>

// void fighterReward::in_contract_transfer(name recipient, vector<id_type> assets_id, string msg)
// {
//   action(
//       permission_level{_self, "active"_n},
//       "atomicassets"_n,
//       "transfer"_n,
//       std::make_tuple(get_self(), recipient, assets_id, msg))
//       .send();
// }

eosio::asset fighterReward::getReward(name username, id_type assets_id, string memo)
{
  require_auth(username);
  auto itr = _user_list.find(username.value);
  check(itr == _user_list.end(), "You don't register in stakerlist");
  action(
      permission_level{_self, "active"_n},
      "atomicassets"_n,
      "transfer"_n,
      std::make_tuple(get_self(), recipient, assets_id, msg))
      .send();
  // _staker_list.modify(itr, _self, [&](auto &a)
}

EOSIO_DISPATCH(fighterReward, (getReward))
