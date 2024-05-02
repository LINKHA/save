%%%-------------------------------------------------------------------
%% @doc gen_statem_test public API
%% @end
%%%-------------------------------------------------------------------

-module(gen_statem_test_app).

-behaviour(application).

-export([start/2, stop/1]).

start(_StartType, _StartArgs) ->
    statem_server:start_link(),
    gen_statem_test_sup:start_link().

stop(_State) ->
    ok.

%% internal functions
