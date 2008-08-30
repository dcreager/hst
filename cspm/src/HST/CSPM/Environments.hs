-----------------------------------------------------------------------
--
--  Copyright © 2008 Douglas Creager
--
--    This library is free software; you can redistribute it and/or
--    modify it under the terms of the GNU Lesser General Public
--    License as published by the Free Software Foundation; either
--    version 2.1 of the License, or (at your option) any later
--    version.
--
--    This library is distributed in the hope that it will be useful,
--    but WITHOUT ANY WARRANTY; without even the implied warranty of
--    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--    GNU Lesser General Public License for more details.
--
--    You should have received a copy of the GNU Lesser General Public
--    License along with this library; if not, write to the Free
--    Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
--    MA 02111-1307 USA
--
------------------------------------------------------------------------

module HST.CSPM.Environments where

import Data.Map (Map)
import qualified Data.Map as Map

import HST.CSPM.Expressions
import HST.CSPM.Values

-- Environments

data Env
    = Env {
        table  :: Map Identifier Expression,
        parent :: Maybe Env
      }
    deriving (Eq, Ord)

rootEnv :: Env
rootEnv = Env Map.empty Nothing

lookupExpr :: Env -> Identifier -> Expression
lookupExpr e id = 
    -- Try to find this id in the current symbol table first.
    case Map.lookup id (table e) of
      -- If we find it, great!  We just return it.
      Just x -> x

      -- Otherwise, we recursively look in the parent environment.
      Nothing -> case (parent e) of
                   Just e1 -> lookupExpr e1 id

                   -- If there is no parent, then the id is undefined.
                   -- Return bottom.
                   Nothing -> EBottom

extendEnv :: Env -> [Binding] -> Env
extendEnv e bs 
    = Env {
        table  = Map.fromAscList ascList,
        parent = Just e
      }
    where
      ascList = map (\ (Binding id x) -> (id, x)) bs
