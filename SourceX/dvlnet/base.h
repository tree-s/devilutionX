#pragma once

#include <string>
#include <map>
#include <deque>
#include <array>
#include <memory>

#include "all.h"
#include "../3rdParty/Storm/Source/storm.h"
#include "dvlnet/abstract_net.h"
#include "dvlnet/packet.h"

namespace dvl {
namespace net {

class base : public abstract_net {
public:
	virtual int create(std::string addrstr, std::string passwd) = 0;
	virtual int join(std::string addrstr, std::string passwd) = 0;

	virtual bool SNetReceiveMessage(int *sender, char **data, int *size);
	virtual bool SNetSendMessage(int dest, void *data, unsigned int size);
	virtual bool SNetReceiveTurns(char **data, unsigned int *size,
	    DWORD *status);
	virtual bool SNetSendTurn(char *data, unsigned int size);
	virtual int SNetGetProviderCaps(struct _SNETCAPS *caps);
	virtual bool SNetRegisterEventHandler(event_type evtype,
	    SEVTHANDLER func);
	virtual bool SNetUnregisterEventHandler(event_type evtype,
	    SEVTHANDLER func);
	virtual bool SNetLeaveGame(int type);
	virtual bool SNetDropPlayer(int playerid, DWORD flags);
	virtual bool SNetGetOwnerTurnsWaiting(DWORD *turns);
	virtual bool SNetGetTurnsInTransit(DWORD *turns);

	virtual void poll() = 0;
	virtual void send(packet &pkt) = 0;

	void setup_gameinfo(buffer_t info);

	virtual ~base() = default;

protected:
	std::map<event_type, SEVTHANDLER> registered_handlers;
	buffer_t game_init_info;

	struct message_t {
		int sender; // change int to something else in devilution code later
		buffer_t payload;
		message_t()
		    : sender(-1)
		    , payload({})
		{
		}
		message_t(int s, buffer_t p)
		    : sender(s)
		    , payload(p)
		{
		}
	};

	message_t message_last;
	std::deque<message_t> message_queue;
	std::array<turn_t, MAX_PLRS> turn_last = {};
	std::array<std::deque<turn_t>, MAX_PLRS> turn_queue;
	std::array<bool, MAX_PLRS> connected_table = {};

	plr_t plr_self = PLR_BROADCAST;
	cookie_t cookie_self = 0;

	std::unique_ptr<packet_factory> pktfty;

	void setup_password(std::string pw);
	void handle_accept(packet &pkt);
	void recv_local(packet &pkt);
	void run_event_handler(_SNETEVENT &ev);

private:
	plr_t get_owner();
	void clear_msg(plr_t plr);
};

} // namespace net
} // namespace dvl
