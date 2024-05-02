%%参考x3项目的
%% gateway.erl
-module(statem_server).
-behavior(gen_statem).

-export([handle_event/3, handle_sync_event/4, handle_info/3,
         terminate/3, code_change/4]).

-export([start_link/0]).

%% gen_statem.
-export([callback_mode/0]).
-export([init/1]).
-export([terminate/3]).
-export([code_change/4]).

%% state_callback
-export([connected/3]).
-export([go_state1/3]).
-export([go_state2/3]).


-record(state, {}).

start_link() ->
    gen_statem:start_link({local, statem_server_name}, ?MODULE, [], []).

init(_) ->
    {ok, connected, #state{}}.


stop_event() ->
    gen_statem:cast(statem_server_name, stop_event).

event1() ->
    gen_statem:cast(statem_server_name, go_to_state1).

event2() ->
    gen_statem:cast(statem_server_name, go_to_state2).


connected(EventType, EventContent, StateData) ->
    io:format("statem server 连接 ~p~n", [""]),
    handle_event(EventType, EventContent, StateData).

handle_event(cast, EventContent, StateData) ->
    io:format("Event 2---------- ~p~n", [EventContent]),
    io:format("Event 3---------- ~p~n", [StateData]),
    case EventContent of
        % 定义状态转换
        stop_event ->
            io:format("stop normal ~p~n", [""]),
            {stop, normal}; %%这里会把这个服务停掉
        go_to_state1 ->
            io:format("go to state1 ~p~n", [""]),
            {next_state, go_state1, StateData};
        go_to_state2 ->
            io:format("go to state2 ~p~n", [""]),
            {next_state, go_state2, StateData};
        _ ->
            io:format("keep state ~p~n", [""]),
            {keep_state, StateData}
    end;
handle_event(info, EventContent, StateData) ->
    io:format("handle event ~p~n", [""]),
    {keep_state, StateData};
handle_event(EventType, EventContent, StateData) ->
    io:format("other handle event ~p~n", [EventType]),
    {keep_state, StateData}.

go_state1(Type, OldStateName, StateData) ->
    {keep_state, StateData}.

go_state2(Type, OldStateName, StateData) ->
    {keep_state, StateData}.

handle_sync_event(Event, From, EventContent, StateData) ->
    Reply = handle_event(Event, EventContent, StateData),
    {reply, Reply, EventContent, StateData}.

handle_info(Info, EventContent, StateData) ->
    {noreply, EventContent, StateData}.

terminate(_Reason, _StateData, _StateName) ->
    ok.

code_change(_OldVsn, StateName, StateData, _Extra) ->
    {ok, StateName, StateData}.

callback_mode() ->
    [state_functions, state_enter].
