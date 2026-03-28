#include "protein_translation.h"
#include <unordered_map>

namespace protein_translation
{
    static const std::unordered_map<std::string, std::string> codon_map{
        {"AUG", "Methionine"},
        {"UUU", "Phenylalanine"},
        {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"},
        {"UUG", "Leucine"},
        {"UCU", "Serine"},
        {"UCC", "Serine"},
        {"UCA", "Serine"},
        {"UCG", "Serine"},
        {"UAU", "Tyrosine"},
        {"UAC", "Tyrosine"},
        {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"},
        {"UAA", "STOP"},
        {"UAG", "STOP"},
        {"UGA", "STOP"},
    };

    std::vector<std::string> proteins(const std::string &strand)
    {
        std::vector<std::string> result;
        std::string codon;
        size_t i{0};

        // while there are more codons
        while (i <= strand.size() - 3)
        {
            // If the current codon exists in our map, we add the corresponding amino acid
            codon = strand.substr(i, 3);

            // If the codon doesn't exist in our map or if it is a STOP codon, we can stop
            auto it = codon_map.find(codon);
            if (it == codon_map.end() || it->second == "STOP")
                break;
            result.push_back(it->second);

            i += 3;
        }

        return result;
    }
} // namespace protein_translation
