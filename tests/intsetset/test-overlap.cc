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

#include <iostream>
#include <hst/intsetset.hh>

using namespace std;
using namespace hst;

int main()
{
    intsetset_t  A, B;
    bool         overlap, actual_overlap;

    while (true)
    {
        cin >> A >> B >> overlap;
        if (!cin.good())
            break;

        cerr << A << " overlaps with " << B << "? ";

        actual_overlap = A.overlaps_with(B);

        if (overlap == actual_overlap)
        {
            cerr << "PASS" << endl;
        } else {
            cerr << "FAIL" << endl;
            return 1;
        }
    }

    return 0;
}
