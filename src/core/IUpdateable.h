#ifndef IUPDATEABLE_H
#define	IUPDATEABLE_H

#include <utils/Time.h>

// NB: updateable and updatable both appear to be acceptable spellings.
// http://dictionary.reference.com/browse/updateable
// http://dictionary.reference.com/browse/updatable
// Silly English language. Gerjo.

class IUpdateable {
public:
    virtual void update(const phantom::PhantomTime& time) = 0;
};

#endif	/* IUPDATEABLE_H */