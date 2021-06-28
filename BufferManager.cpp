#include "BufferManager.h"

#include <Buffer.h>

namespace gnote {

BufferManager* BufferManager::getInstance() {
    static BufferManager bufferManager;
    return &bufferManager;
}

BufferManager::BufferManager() {
    m_pBufferHash = new QHash<QString, Buffer *>();
}

Buffer *BufferManager::getBuffer(const QString &path) {
    BUFFER_HASH_TYPE::const_iterator it = m_pBufferHash->find(path);
    if (m_pBufferHash->end() == it) {
        Buffer *newBuffer = new Buffer(path);
        m_pBufferHash->insert(path, newBuffer);
        return newBuffer;
    }

    return it.value();
}


BufferManager::~BufferManager() {
}

}
