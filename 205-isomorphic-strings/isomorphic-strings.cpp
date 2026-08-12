class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // Store the mapping from characters of s to characters of t.
        vector<pair<char, char>> mappings;

        for (int i = 0; i < s.size(); i++) {

            char source = s[i];
            char target = t[i];

            bool sourceFound = false;
            bool targetAlreadyUsed = false;

            // Search whether source character already has a mapping.
            for (auto mapping : mappings) {

                // Found the existing mapping for the source character.
                if (mapping.first == source) {
                    sourceFound = true;

                    // If it maps to a different character,
                    // the strings cannot be isomorphic.
                    if (mapping.second != target) {
                        return false;
                    }
                }

                // Check whether another source character is already
                // mapped to this target character.
                if (mapping.second == target &&
                    mapping.first != source) {
                    targetAlreadyUsed = true;
                }
            }

            // A new source character cannot map to a target character
            // that is already assigned to another source character.
            if (!sourceFound && targetAlreadyUsed) {
                return false;
            }

            // Create a new mapping if this source character is new.
            if (!sourceFound) {
                mappings.push_back({source, target});
            }
        }

        return true;
    }
};