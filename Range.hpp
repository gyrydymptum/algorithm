
#pragma once

struct Range{
    using It = DicesContainer::const_iterator;
    using ItR = DicesContainer::const_reverse_iterator;

    Range(const DicesContainer &container) 
        : cb(container.cbegin()),
        ce(container.cbegin()),
        crb(container.crbegin()),
        cre(container.crbegin()) {}

    Range(const DicesContainer &container, size_t num) 
        : cb(container.cbegin()),
        ce(advance(container.cbegin(), num)),
        crb(container.crbegin()),
        cre(advance(container.crbegin(), num)) {}

    template<typename T>
    T advance(T e, size_t num)const{
        std::advance(e, num);
        return e;
    }
    
    size_t size() const{
        return std::distance(cb, ce);
    }

    auto begin() const{
        return this->cb;
    }

    auto end() const{
        return this->ce;
    }

    auto cbegin() const{
        return this->cb;
    }

    auto cend() const{
        return this->ce;
    }

    auto crbegin() const{
        return this->crb;
    }

    auto crend() const{
        return this->cre;
    }
private:
    const It cb;
    const It ce;
    const ItR crb;
    const ItR cre;
};
