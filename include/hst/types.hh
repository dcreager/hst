/*----------------------------------------------------------------------
 *
 *  Copyright © 2007, 2008 Douglas Creager
 *
 *    This library is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 2.1 of the License, or (at your option) any later
 *    version.
 *
 *    This library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with this library; if not, write to the Free
 *    Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 *    MA 02111-1307 USA
 *
 *----------------------------------------------------------------------
 */

#ifndef HST_TYPES_HH
#define HST_TYPES_HH

#include <deque>
#include <functional>

#include <boost/shared_ptr.hpp>

#include <hst/intset.hh>
#include <hst/intsetset.hh>

/*
 * We will treat -1 (0xFFFFFFFF) as an error code, and will never
 * create a state or event with this number.
 */

#define HST_ERROR_STATE  ((hst::state_t) (-1))
#define HST_ERROR_EVENT  ((hst::event_t) (-1))

namespace hst
{
    enum semantic_model_t
    {
        TRACES,
        FAILURES,
        FAILURES_DIVERGENCES
    };

    typedef unsigned long  state_t;

    typedef intset_t   stateset_t;
    typedef intset_p   stateset_p;
    typedef intset_cp  stateset_cp;

    struct state_t_hasher
    {
        unsigned long operator () (const state_t state) const
        {
            return state;
        }
    };

    typedef unsigned long  event_t;

    typedef intset_t   alphabet_t;
    typedef intset_p   alphabet_p;
    typedef intset_cp  alphabet_cp;

    typedef intsetset_t   alphabet_set_t;
    typedef intsetset_p   alphabet_set_p;
    typedef intsetset_cp  alphabet_set_cp;

    struct event_t_hasher
    {
        unsigned long operator () (const event_t event) const
        {
            return event;
        }
    };

    /**
     * A filter functor that can be used with Boost's filter_transform
     * to skip over τ events.
     */

    struct skip_taus:
        public std::unary_function<event_t, bool>
    {
    protected:
        event_t  tau;

    public:
        skip_taus()
        {
        }

        skip_taus(event_t _tau):
            tau(_tau)
        {
        }

        result_type operator () (argument_type event)
        {
            return (event != tau);
        }
    };

    typedef std::deque<event_t>               trace_t;
    typedef boost::shared_ptr<trace_t>        trace_p;
    typedef boost::shared_ptr<const trace_t>  trace_cp;

    typedef std::pair<state_t, state_t>             state_state_t;
    typedef boost::shared_ptr<state_state_t>        state_state_p;
    typedef boost::shared_ptr<const state_state_t>  state_state_cp;

    typedef std::pair<event_t, state_t>             event_state_t;
    typedef boost::shared_ptr<event_state_t>        event_state_p;
    typedef boost::shared_ptr<const event_state_t>  event_state_cp;

    struct string_hasher
    {
        unsigned long operator () (const std::string &str) const
        {
            unsigned long  hash = 0L;
            for (std::string::const_iterator it = str.begin();
                 it != str.end(); ++it)
            {
                hash += *it;
                hash += (hash << 10);
                hash ^= (hash >> 6);
            }

            hash += (hash << 3);
            hash ^= (hash >> 11);
            hash += (hash << 15);

            return hash;
        }
    };
}

#endif // HST_TYPES_H
